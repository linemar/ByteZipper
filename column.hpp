/*
 * @Author: SunZewen
 * @Date: 2023-03-27 10:04:06
 * @LastEditors: SunZewen
 * @LastEditTime: 2023-06-29 20:13:26
 * @Description:
 * @FilePath: /zwsun/workspace/iot_cloud/iot/include/bytesegment/storage/column.hpp
 */

#ifndef COMPRESSCOLUMN
#define COMPRESSCOLUMN

#include <vector>
#include <cstdint>
#include <cstddef>

#include "block.hpp"

typedef bool mask;
// const uint32_t block_data_size = 128;

namespace bytesegment
{
    namespace integer32
    {
        struct Column_B32I_D32U
        {
            uint32_t group_size = block_data_size;
            std::vector<int32_t> *index;
            std::vector<Block_D32U> *metadata;
        };

        struct Column_B32I_D16U_NP_P
        {
            uint32_t group_size = block_data_size;
            std::vector<int32_t> *index;
            std::vector<Block_D16U_NP_P> *metadata;
        };

        struct Column_B32I_D8U_P8UP_NBP
        {
            uint32_t group_size = block_data_size;
            std::vector<int32_t> *index;
            std::vector<Block_D8U_P8UP> *metadata;
        };
    }
}

#endif