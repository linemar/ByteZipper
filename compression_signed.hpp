#ifndef SINGED_BITPACKING_H_
#define SINGED_BITPACKING_H_

#include "bpacking_signed.hpp"
#include "unbpacking_signed.hpp"

namespace common
{
    namespace bitpacking
    {
        namespace signed_integer
        {
            compression::unbitpacking::signed_integer::unpackfnc unpack8[33] = {compression::unbitpacking::signed_integer::nullunpacker8,
                                                                                compression::unbitpacking::signed_integer::unpack1_8,
                                                                                compression::unbitpacking::signed_integer::unpack2_8,
                                                                                compression::unbitpacking::signed_integer::unpack3_8,
                                                                                compression::unbitpacking::signed_integer::unpack4_8,
                                                                                compression::unbitpacking::signed_integer::unpack5_8,
                                                                                compression::unbitpacking::signed_integer::unpack6_8,
                                                                                compression::unbitpacking::signed_integer::unpack7_8,
                                                                                compression::unbitpacking::signed_integer::unpack8_8,
                                                                                compression::unbitpacking::signed_integer::unpack9_8,
                                                                                compression::unbitpacking::signed_integer::unpack10_8,
                                                                                compression::unbitpacking::signed_integer::unpack11_8,
                                                                                compression::unbitpacking::signed_integer::unpack12_8,
                                                                                compression::unbitpacking::signed_integer::unpack13_8,
                                                                                compression::unbitpacking::signed_integer::unpack14_8,
                                                                                compression::unbitpacking::signed_integer::unpack15_8,
                                                                                compression::unbitpacking::signed_integer::unpack16_8,
                                                                                compression::unbitpacking::signed_integer::unpack17_8,
                                                                                compression::unbitpacking::signed_integer::unpack18_8,
                                                                                compression::unbitpacking::signed_integer::unpack19_8,
                                                                                compression::unbitpacking::signed_integer::unpack20_8,
                                                                                compression::unbitpacking::signed_integer::unpack21_8,
                                                                                compression::unbitpacking::signed_integer::unpack22_8,
                                                                                compression::unbitpacking::signed_integer::unpack23_8,
                                                                                compression::unbitpacking::signed_integer::unpack24_8,
                                                                                compression::unbitpacking::signed_integer::unpack25_8,
                                                                                compression::unbitpacking::signed_integer::unpack26_8,
                                                                                compression::unbitpacking::signed_integer::unpack27_8,
                                                                                compression::unbitpacking::signed_integer::unpack28_8,
                                                                                compression::unbitpacking::signed_integer::unpack29_8,
                                                                                compression::unbitpacking::signed_integer::unpack30_8,
                                                                                compression::unbitpacking::signed_integer::unpack31_8,
                                                                                compression::unbitpacking::signed_integer::unpack32_8};

            compression::bitpacking::signed_integer::packfnc pack8[33] = {compression::bitpacking::signed_integer::nullpacker,
                                                                          compression::bitpacking::signed_integer::pack1_8,
                                                                          compression::bitpacking::signed_integer::pack2_8,
                                                                          compression::bitpacking::signed_integer::pack3_8,
                                                                          compression::bitpacking::signed_integer::pack4_8,
                                                                          compression::bitpacking::signed_integer::pack5_8,
                                                                          compression::bitpacking::signed_integer::pack6_8,
                                                                          compression::bitpacking::signed_integer::pack7_8,
                                                                          compression::bitpacking::signed_integer::pack8_8,
                                                                          compression::bitpacking::signed_integer::pack9_8,
                                                                          compression::bitpacking::signed_integer::pack10_8,
                                                                          compression::bitpacking::signed_integer::pack11_8,
                                                                          compression::bitpacking::signed_integer::pack12_8,
                                                                          compression::bitpacking::signed_integer::pack13_8,
                                                                          compression::bitpacking::signed_integer::pack14_8,
                                                                          compression::bitpacking::signed_integer::pack15_8,
                                                                          compression::bitpacking::signed_integer::pack16_8,
                                                                          compression::bitpacking::signed_integer::pack17_8,
                                                                          compression::bitpacking::signed_integer::pack18_8,
                                                                          compression::bitpacking::signed_integer::pack19_8,
                                                                          compression::bitpacking::signed_integer::pack20_8,
                                                                          compression::bitpacking::signed_integer::pack21_8,
                                                                          compression::bitpacking::signed_integer::pack22_8,
                                                                          compression::bitpacking::signed_integer::pack23_8,
                                                                          compression::bitpacking::signed_integer::pack24_8,
                                                                          compression::bitpacking::signed_integer::pack25_8,
                                                                          compression::bitpacking::signed_integer::pack26_8,
                                                                          compression::bitpacking::signed_integer::pack27_8,
                                                                          compression::bitpacking::signed_integer::pack28_8,
                                                                          compression::bitpacking::signed_integer::pack29_8,
                                                                          compression::bitpacking::signed_integer::pack30_8,
                                                                          compression::bitpacking::signed_integer::pack31_8,
                                                                          compression::bitpacking::signed_integer::pack32_8};

            compression::unbitpacking::signed_integer::unpackfnc unpack16[33] = {compression::unbitpacking::signed_integer::nullunpacker16,
                                                                                 compression::unbitpacking::signed_integer::unpack1_16,
                                                                                 compression::unbitpacking::signed_integer::unpack2_16,
                                                                                 compression::unbitpacking::signed_integer::unpack3_16,
                                                                                 compression::unbitpacking::signed_integer::unpack4_16,
                                                                                 compression::unbitpacking::signed_integer::unpack5_16,
                                                                                 compression::unbitpacking::signed_integer::unpack6_16,
                                                                                 compression::unbitpacking::signed_integer::unpack7_16,
                                                                                 compression::unbitpacking::signed_integer::unpack8_16,
                                                                                 compression::unbitpacking::signed_integer::unpack9_16,
                                                                                 compression::unbitpacking::signed_integer::unpack10_16,
                                                                                 compression::unbitpacking::signed_integer::unpack11_16,
                                                                                 compression::unbitpacking::signed_integer::unpack12_16,
                                                                                 compression::unbitpacking::signed_integer::unpack13_16,
                                                                                 compression::unbitpacking::signed_integer::unpack14_16,
                                                                                 compression::unbitpacking::signed_integer::unpack15_16,
                                                                                 compression::unbitpacking::signed_integer::unpack16_16,
                                                                                 compression::unbitpacking::signed_integer::unpack17_16,
                                                                                 compression::unbitpacking::signed_integer::unpack18_16,
                                                                                 compression::unbitpacking::signed_integer::unpack19_16,
                                                                                 compression::unbitpacking::signed_integer::unpack20_16,
                                                                                 compression::unbitpacking::signed_integer::unpack21_16,
                                                                                 compression::unbitpacking::signed_integer::unpack22_16,
                                                                                 compression::unbitpacking::signed_integer::unpack23_16,
                                                                                 compression::unbitpacking::signed_integer::unpack24_16,
                                                                                 compression::unbitpacking::signed_integer::unpack25_16,
                                                                                 compression::unbitpacking::signed_integer::unpack26_16,
                                                                                 compression::unbitpacking::signed_integer::unpack27_16,
                                                                                 compression::unbitpacking::signed_integer::unpack28_16,
                                                                                 compression::unbitpacking::signed_integer::unpack29_16,
                                                                                 compression::unbitpacking::signed_integer::unpack30_16,
                                                                                 compression::unbitpacking::signed_integer::unpack31_16,
                                                                                 compression::unbitpacking::signed_integer::unpack32_16};

            compression::bitpacking::signed_integer::packfnc pack16[33] = {compression::bitpacking::signed_integer::nullpacker,
                                                                           compression::bitpacking::signed_integer::pack1_16,
                                                                           compression::bitpacking::signed_integer::pack2_16,
                                                                           compression::bitpacking::signed_integer::pack3_16,
                                                                           compression::bitpacking::signed_integer::pack4_16,
                                                                           compression::bitpacking::signed_integer::pack5_16,
                                                                           compression::bitpacking::signed_integer::pack6_16,
                                                                           compression::bitpacking::signed_integer::pack7_16,
                                                                           compression::bitpacking::signed_integer::pack8_16,
                                                                           compression::bitpacking::signed_integer::pack9_16,
                                                                           compression::bitpacking::signed_integer::pack10_16,
                                                                           compression::bitpacking::signed_integer::pack11_16,
                                                                           compression::bitpacking::signed_integer::pack12_16,
                                                                           compression::bitpacking::signed_integer::pack13_16,
                                                                           compression::bitpacking::signed_integer::pack14_16,
                                                                           compression::bitpacking::signed_integer::pack15_16,
                                                                           compression::bitpacking::signed_integer::pack16_16,
                                                                           compression::bitpacking::signed_integer::pack17_16,
                                                                           compression::bitpacking::signed_integer::pack18_16,
                                                                           compression::bitpacking::signed_integer::pack19_16,
                                                                           compression::bitpacking::signed_integer::pack20_16,
                                                                           compression::bitpacking::signed_integer::pack21_16,
                                                                           compression::bitpacking::signed_integer::pack22_16,
                                                                           compression::bitpacking::signed_integer::pack23_16,
                                                                           compression::bitpacking::signed_integer::pack24_16,
                                                                           compression::bitpacking::signed_integer::pack25_16,
                                                                           compression::bitpacking::signed_integer::pack26_16,
                                                                           compression::bitpacking::signed_integer::pack27_16,
                                                                           compression::bitpacking::signed_integer::pack28_16,
                                                                           compression::bitpacking::signed_integer::pack29_16,
                                                                           compression::bitpacking::signed_integer::pack30_16,
                                                                           compression::bitpacking::signed_integer::pack31_16,
                                                                           compression::bitpacking::signed_integer::pack32_16};

            compression::unbitpacking::signed_integer::unpackfnc unpack32[33] = {compression::unbitpacking::signed_integer::nullunpacker32,
                                                                                 compression::unbitpacking::signed_integer::unpack1_32,
                                                                                 compression::unbitpacking::signed_integer::unpack2_32,
                                                                                 compression::unbitpacking::signed_integer::unpack3_32,
                                                                                 compression::unbitpacking::signed_integer::unpack4_32,
                                                                                 compression::unbitpacking::signed_integer::unpack5_32,
                                                                                 compression::unbitpacking::signed_integer::unpack6_32,
                                                                                 compression::unbitpacking::signed_integer::unpack7_32,
                                                                                 compression::unbitpacking::signed_integer::unpack8_32,
                                                                                 compression::unbitpacking::signed_integer::unpack9_32,
                                                                                 compression::unbitpacking::signed_integer::unpack10_32,
                                                                                 compression::unbitpacking::signed_integer::unpack11_32,
                                                                                 compression::unbitpacking::signed_integer::unpack12_32,
                                                                                 compression::unbitpacking::signed_integer::unpack13_32,
                                                                                 compression::unbitpacking::signed_integer::unpack14_32,
                                                                                 compression::unbitpacking::signed_integer::unpack15_32,
                                                                                 compression::unbitpacking::signed_integer::unpack16_32,
                                                                                 compression::unbitpacking::signed_integer::unpack17_32,
                                                                                 compression::unbitpacking::signed_integer::unpack18_32,
                                                                                 compression::unbitpacking::signed_integer::unpack19_32,
                                                                                 compression::unbitpacking::signed_integer::unpack20_32,
                                                                                 compression::unbitpacking::signed_integer::unpack21_32,
                                                                                 compression::unbitpacking::signed_integer::unpack22_32,
                                                                                 compression::unbitpacking::signed_integer::unpack23_32,
                                                                                 compression::unbitpacking::signed_integer::unpack24_32,
                                                                                 compression::unbitpacking::signed_integer::unpack25_32,
                                                                                 compression::unbitpacking::signed_integer::unpack26_32,
                                                                                 compression::unbitpacking::signed_integer::unpack27_32,
                                                                                 compression::unbitpacking::signed_integer::unpack28_32,
                                                                                 compression::unbitpacking::signed_integer::unpack29_32,
                                                                                 compression::unbitpacking::signed_integer::unpack30_32,
                                                                                 compression::unbitpacking::signed_integer::unpack31_32,
                                                                                 compression::unbitpacking::signed_integer::unpack32_32};

            compression::bitpacking::signed_integer::packfnc pack32[33] = {compression::bitpacking::signed_integer::nullpacker, compression::bitpacking::signed_integer::pack1_32,
                                                                           compression::bitpacking::signed_integer::pack2_32,
                                                                           compression::bitpacking::signed_integer::pack3_32,
                                                                           compression::bitpacking::signed_integer::pack4_32,
                                                                           compression::bitpacking::signed_integer::pack5_32,
                                                                           compression::bitpacking::signed_integer::pack6_32,
                                                                           compression::bitpacking::signed_integer::pack7_32,
                                                                           compression::bitpacking::signed_integer::pack8_32,
                                                                           compression::bitpacking::signed_integer::pack9_32,
                                                                           compression::bitpacking::signed_integer::pack10_32,
                                                                           compression::bitpacking::signed_integer::pack11_32,
                                                                           compression::bitpacking::signed_integer::pack12_32,
                                                                           compression::bitpacking::signed_integer::pack13_32,
                                                                           compression::bitpacking::signed_integer::pack14_32,
                                                                           compression::bitpacking::signed_integer::pack15_32,
                                                                           compression::bitpacking::signed_integer::pack16_32,
                                                                           compression::bitpacking::signed_integer::pack17_32,
                                                                           compression::bitpacking::signed_integer::pack18_32,
                                                                           compression::bitpacking::signed_integer::pack19_32,
                                                                           compression::bitpacking::signed_integer::pack20_32,
                                                                           compression::bitpacking::signed_integer::pack21_32,
                                                                           compression::bitpacking::signed_integer::pack22_32,
                                                                           compression::bitpacking::signed_integer::pack23_32,
                                                                           compression::bitpacking::signed_integer::pack24_32,
                                                                           compression::bitpacking::signed_integer::pack25_32,
                                                                           compression::bitpacking::signed_integer::pack26_32,
                                                                           compression::bitpacking::signed_integer::pack27_32,
                                                                           compression::bitpacking::signed_integer::pack28_32,
                                                                           compression::bitpacking::signed_integer::pack29_32,
                                                                           compression::bitpacking::signed_integer::pack30_32,
                                                                           compression::bitpacking::signed_integer::pack31_32,
                                                                           compression::bitpacking::signed_integer::pack32_32};

            inline uint32_t bits(const uint32_t v)
            {
                return v == 0 ? 0 : 32 - __builtin_clz(v);
            }

            inline uint32_t *compress_duckdb(int32_t *in, uint32_t length, int32_t &min, uint32_t *out, uint8_t &bit_len)
            {
                if (length == 0)
                    return out;

                int32_t m = in[0];
                int32_t M = in[0];

                for (uint32_t i = 1; i < length; ++i)
                {
                    if (in[i] > M)
                        M = in[i];

                    if (in[i] < m)
                        m = in[i];
                }

                int b = bits(static_cast<uint32_t>(M - m));
                bit_len = b;

                uint32_t k = 0;
                for (; k + 32 <= length; k += 32, in += 32)
                {
                    out = pack32[b](m, in, out);
                }

                min = m;
                return out;
            }

            inline uint32_t *uncompress_duckdb(int32_t m, uint32_t *in, int32_t *out, uint32_t nvalue, uint8_t bit_len)
            {
                if (nvalue == 0)
                    return in;

                int b = (int)bit_len;
                for (uint32_t k = 0; k < nvalue / 32; ++k)
                {
                    unpack32[b](m, in + b * k, out + 32 * k);
                }

                return in;
            }

            inline uint32_t *compress(int32_t *in, uint32_t length, int32_t &min, int32_t &max, uint32_t *out, uint8_t &bit_len)
            {
                out[0] = length;
                ++out;

                if (length == 0)
                    return out;

                int32_t m = in[0];
                int32_t M = in[0];

                for (uint32_t i = 1; i < length; ++i)
                {
                    if (in[i] > M)
                        M = in[i];

                    if (in[i] < m)
                        m = in[i];
                }

                int b = bits(static_cast<uint32_t>(M - m));
                bit_len = b;

                // out[0] = m;
                // ++out;
                // out[0] = M;
                // ++out;

                uint32_t k = 0;

                for (; k + 32 <= length; k += 32, in += 32)
                {
                    out = pack32[b](m, in, out);
                }

                for (; k + 16 <= length; k += 16, in += 16)
                {
                    out = pack16[b](m, in, out);
                }

                for (; k + 8 <= length; k += 8, in += 8)
                {
                    out = pack8[b](m, in, out);
                }

                // we could pack the rest, but we don't  bother
                for (; k < length; ++k, in++, out++)
                {
                    out[0] = in[0];
                }

                min = m;
                max = M;

                return out;
            }

            inline uint32_t *compress(int32_t *in, uint32_t length, int32_t &min, uint32_t *out, uint8_t &bit_len)
            {
                out[0] = length;
                ++out;

                if (length == 0)
                    return out;

                int32_t m = in[0];
                int32_t M = in[0];

                for (uint32_t i = 1; i < length; ++i)
                {
                    if (in[i] > M)
                        M = in[i];

                    if (in[i] < m)
                        m = in[i];
                }

                int b = bits(static_cast<uint32_t>(M - m));
                bit_len = b;

                // std::cout  << "bits : " << b << std::endl;

                out[0] = m;
                ++out;

                out[0] = M;
                ++out;

                uint32_t k = 0;

                for (; k + 32 <= length; k += 32, in += 32)
                {
                    out = pack32[b](m, in, out);
                }

                for (; k + 16 <= length; k += 16, in += 16)
                {
                    out = pack16[b](m, in, out);
                }

                for (; k + 8 <= length; k += 8, in += 8)
                {
                    out = pack8[b](m, in, out);
                }

                // we could pack the rest, but we don't  bother
                for (; k < length; ++k, in++, out++)
                {
                    out[0] = in[0];
                }

                min = m;

                return out;
            }

            inline uint32_t *compress(int32_t *in, uint32_t length, uint32_t *out, uint32_t &bit_len)
            {
                out[0] = length;
                ++out;

                if (length == 0)
                    return out;

                int32_t m = in[0];
                int32_t M = in[0];

                for (uint32_t i = 1; i < length; ++i)
                {
                    if (in[i] > M)
                        M = in[i];

                    if (in[i] < m)
                        m = in[i];
                }

                int b = bits(static_cast<uint32_t>(M - m));
                bit_len = b;

                // std::cout  << "bits : " << b << std::endl;

                out[0] = m;
                ++out;

                out[0] = M;
                ++out;

                uint32_t k = 0;

                for (; k + 32 <= length; k += 32, in += 32)
                {
                    out = pack32[b](m, in, out);
                }

                for (; k + 16 <= length; k += 16, in += 16)
                {
                    out = pack16[b](m, in, out);
                }

                for (; k + 8 <= length; k += 8, in += 8)
                {
                    out = pack8[b](m, in, out);
                }

                // we could pack the rest, but we don't  bother
                for (; k < length; ++k, in++, out++)
                {
                    out[0] = in[0];
                }

                return out;
            }

            inline uint32_t *uncompress(uint32_t *in, int32_t *out, uint32_t &nvalue)
            {
                nvalue = in[0];
                ++in;

                if (nvalue == 0)
                    return in;

                uint32_t m = in[0];
                ++in;

                uint32_t M = in[0];
                ++in;

                int b = bits(static_cast<uint32_t>(M - m));

                for (uint32_t k = 0; k < nvalue / 32; ++k)
                {
                    unpack32[b](m, in + b * k, out + 32 * k);
                }

                out = out + nvalue / 32 * 32;
                in = in + nvalue / 32 * b;

                for (uint32_t k = nvalue / 32 * 32; k + 16 <= nvalue; k += 16, out += 16)
                {
                    in = unpack16[b](m, in, out);
                }

                for (uint32_t k = nvalue / 16 * 16; k + 8 <= nvalue; k += 8, out += 8)
                {
                    in = unpack8[b](m, in, out);
                }

                // we could pack the rest, but we don't  bother
                for (uint32_t k = nvalue / 8 * 8; k < nvalue; ++k, in++, out++)
                {
                    out[0] = in[0];
                }

                return in;
            }
        }
    }
}

#endif
