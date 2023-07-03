/*
 * @Author: SunZewen
 * @Date: 2023-03-25 19:55:07
 * @LastEditors: SunZewen
 * @LastEditTime: 2023-07-03 12:45:02
 * @Description:
 * @FilePath: \undefinedc:\Users\SunZewen\Desktop\bcompression32 (1).hpp
 */

#include <vector>
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <unistd.h>


#include "block.hpp"
#include "column.hpp"
#include "function32.hpp"
#include "compression.h"
#include "compression_signed.hpp"


namespace bytesegment
{
    // block compression
    namespace column
    {
        namespace bit32
        {
            // for column compression
            inline int bcompression_min_v(int32_t *src, bytesegment::integer32::Column_B32I_D8U_P8UP_NBP *col, uint32_t block_data_size, size_t len)
            {
                size_t loop_times = len / block_data_size;

                int32_t base = 0;
                __mmask16 mask_true_ = 0xffff;
                size_t index = 0;
                __mmask16 mask_gt255 = 0xffff;
                __m512i data_255 = _mm512_set1_epi32(255);
                __m512i delta_high_vec = _mm512_set1_epi32(0);

                for (size_t block_id = 0; block_id < loop_times; block_id++)
                {
                    size_t index = block_data_size * block_id;
                    get_min(&src[index], block_data_size, base);

                    (*col->index)[block_id] = base;
                    // pack_size = 0;

                    __m512i base_vec = _mm512_set1_epi32(base);

                    for (size_t i = 0; i < block_data_size; i = i + 16)
                    {
                        __m512i bytedata_vec = _mm512_loadu_epi32(src + index + i);
                        __m512i delta_vec = _mm512_sub_epi32(bytedata_vec, base_vec);

                        // 所有元素的低8位都要存储在comp数组
                        _mm512_mask_cvtepi32_storeu_epi8((*(col->metadata))[block_id].comp_data + i, mask_true_, delta_vec);

                        // 与255比较
                        mask_gt255 = _mm512_cmpgt_epi32_mask(delta_vec, data_255);
                        ((uint16_t *)(*(col->metadata))[block_id].bmask)[i >> 4] = mask_gt255;

                        // delta_high_vec = delta_vec >> 8;
                        delta_high_vec = _mm512_srli_epi32(delta_vec, 8);

                        // 大于255的部分需要移位，然后存储
                        _mm_mask_compressstoreu_epi8((*(col->metadata))[block_id].pack_data + (*(col->metadata))[block_id].pack_data_size, mask_gt255, _mm512_cvtepi32_epi8(delta_high_vec));
                        (*(col->metadata))[block_id].pack_data_size += _mm_popcnt_u32((uint32_t)mask_gt255);
                    }

                    index += block_data_size;
                }

                return 0;
            }

            inline int buncompression_min_v(bytesegment::integer32::Column_B32I_D8U_P8UP_NBP *col, int32_t *out, uint32_t block_data_size, size_t len)
            {
                size_t loop_times = len / block_data_size;

                int32_t base = 0;
                uint8_t bit_len = 0;
                uint8_t pack_size = 0;
                uint32_t delta = 0;
                uint8_t bit_mask = 0x01;
                __mmask16 mask_true_ = 0xffff;
                size_t offset = 0;
                __mmask16 mask_gt255 = 0xffff;
                __mmask16 mask_true_16 = 0xffff;
                __mmask32 mask_true_32 = 0xffffffff;

                uint16_t high_rids[block_data_size];
                int32_t high_data[block_data_size];

                uint64_t high_rids_size = 0;

                // uint8_t rid_ofsset_arr_8[block_data_size];
                uint16_t rid_ofsset_arr_16[block_data_size];
                for (uint32_t i = 0; i < block_data_size; i++)
                {
                    // rid_ofsset_arr_8[i] = (uint8_t)i;
                    rid_ofsset_arr_16[i] = (uint16_t)i;
                }

                __m512i rid_offset_vec_16 = _mm512_maskz_loadu_epi16(mask_true_32, rid_ofsset_arr_16);

                for (size_t block_id = 0; block_id < loop_times; block_id++)
                {
                    high_rids_size = 0;
                    size_t k = 0;
                    // for (; k + 32 < (*col->metadata)[block_id].pack_data_size; k = k + 32)
                    for (; k < block_data_size; k = k + 32)
                    {
                        __mmask32 mask_src_high = (*((__mmask32 *)(*col->metadata)[block_id].bmask + (k >> 5)));
                        __m512i k_vec = _mm512_set1_epi16((uint16_t)k);
                        __m512i rid_offset_vec = _mm512_add_epi16(k_vec, rid_offset_vec_16);
                        // __m512i rid_offset_vec = _mm512_maskz_loadu_epi16(mask_true_, rid_ofsset_arr_16 + k);
                        _mm512_mask_compressstoreu_epi16(high_rids + high_rids_size, mask_src_high, rid_offset_vec);

                        high_rids_size += _mm_popcnt_u32(mask_src_high);
                    }

                    // scatter high byte data
                    k = 0;
                    for (; k + 16 < (*col->metadata)[block_id].pack_data_size; k = k + 16)
                    {
                        __m512i rid_offset_vec = _mm512_cvtepu16_epi32(_mm256_maskz_loadu_epi16(mask_true_, high_rids + k));
                        __m512i high_bytes = _mm512_cvtepu8_epi32(_mm_maskz_loadu_epi8(mask_true_, (*col->metadata)[block_id].pack_data + k));

                        _mm512_i32scatter_epi32(high_data, rid_offset_vec, high_bytes, 4);
                    }

                    if (k < (*col->metadata)[block_id].pack_data_size)
                    {
                        __mmask16 mask_left = mask_true_16 >> (16 - ((*col->metadata)[block_id].pack_data_size - k));
                        __m512i rid_offset_vec = _mm512_cvtepu16_epi32(_mm256_maskz_loadu_epi16(mask_left, high_rids + k));
                        __m512i high_bytes = _mm512_cvtepu8_epi32(_mm_maskz_loadu_epi8(mask_left, (*col->metadata)[block_id].pack_data + k));

                        _mm512_mask_i32scatter_epi32(high_data, mask_left, rid_offset_vec, high_bytes, 4);
                    }

                    __m512i base_vec = _mm512_set1_epi32((*col->index)[block_id]);
                    for (size_t i = 0; i < block_data_size; i = i + 16)
                    {
                        // load high
                        __mmask16 mask_src_high = (*((__mmask16 *)(*col->metadata)[block_id].bmask + (i >> 4)));
                        __m512i deltas_high = _mm512_maskz_loadu_epi32(mask_src_high, high_data + i);

                        // load low
                        __m512i deltas_low = _mm512_cvtepu8_epi32(_mm_maskz_loadu_epi8(mask_true_, (*col->metadata)[block_id].comp_data + i));

                        // add
                        deltas_high = _mm512_slli_epi32(deltas_high, 8);
                        __m512i ori_data_vec = _mm512_add_epi32(deltas_low, deltas_high);
                        ori_data_vec = _mm512_add_epi32(base_vec, ori_data_vec);

                        // store
                        _mm512_storeu_epi32(out + offset, ori_data_vec);
                        offset = 16 + offset;
                    }
                }

                return 0;
            }

            inline int bcompression_min_gbp(int32_t *src, bytesegment::integer32::Column_B32I_D32U *col, uint32_t block_data_size, size_t len)
            {
                size_t loop_times = len / block_data_size;
                size_t offset = 0;

                for (size_t block_id = 0; block_id < loop_times; block_id++)
                {
                    common::bitpacking::signed_integer::compress_duckdb(src + offset, block_data_size, (*col->index)[block_id], (*col->metadata)[block_id].data, (*col->metadata)[block_id].bit_len);
                    offset += block_data_size;
                }

                return 0;
            }

            inline int buncompression_min_gbp(bytesegment::integer32::Column_B32I_D32U *col, int32_t *out, uint32_t block_data_size, size_t len)
            {
                size_t loop_times = len / block_data_size;
                size_t offset = 0;

                for (size_t block_id = 0; block_id < loop_times; block_id++)
                {
                    common::bitpacking::signed_integer::uncompress_duckdb((*col->index)[block_id], (*col->metadata)[block_id].data, out + offset, block_data_size, (*col->metadata)[block_id].bit_len);
                    offset += block_data_size;
                }

                return 0;
            }
            

            inline int bcompression_min_v(int32_t *src, bytesegment::integer32::Column_B32I_D16U_NP_P *col, uint32_t block_data_size, size_t len)
            {
                size_t loop_times = len / block_data_size;
                // bytesegment::integer32::Block_D8U_NP block;

                int32_t base = 0;
                uint32_t delta = 0;
                size_t index = 0;
                __mmask16 mask_true_ = 0xffff;
                std::vector<int32_t> *bases = col->index;

                for (size_t block_id = 0; block_id < loop_times; block_id++)
                {
                    get_min(src + index, block_data_size, base);
                    (*(bases))[block_id] = base;
                    __m512i base_vec = _mm512_set1_epi32(base);

                    for (size_t i = 0; i < block_data_size; i = i + 16)
                    {
                        __m512i bytedata_vec = _mm512_loadu_epi32(src + index + i);
                        __m512i delta_vec = _mm512_sub_epi32(bytedata_vec, base_vec);

                        _mm512_mask_cvtepi32_storeu_epi16((*(col->metadata))[block_id].comp_data + i, mask_true_, delta_vec);
                    }

                    index = block_data_size + index;
                }

                return 0;
            }


            inline int buncompression_min_v(bytesegment::integer32::Column_B32I_D16U_NP_P *col, int32_t *out, uint32_t block_data_size, size_t len)
            {
                size_t loop_times = len / block_data_size;

                int32_t base = 0;
                uint32_t delta = 0;
                size_t offset = 0;
                __mmask16 mask_true_ = 0xffff;
                std::vector<int32_t> *bases = col->index;

                for (size_t block_id = 0; block_id < loop_times; block_id++)
                {
                    __m512i base_vec = _mm512_set1_epi32(bases->data()[block_id]);

                    for (size_t i = 0; i < block_data_size; i = i + 16)
                    {
                        __m512i deltas = _mm512_cvtepu16_epi32(_mm256_maskz_loadu_epi16(mask_true_, (*col->metadata)[block_id].comp_data + i));
                        // add
                        __m512i ori_data_vec = _mm512_add_epi32(base_vec, deltas);

                        // store
                        _mm512_storeu_epi32(out + offset, ori_data_vec);

                        offset = 16 + offset;
                    }
                }

                return 0;
            }
        }
    }
}
