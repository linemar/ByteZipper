/*
 * @Author: SunZewen
 * @Date: 2023-05-31 13:18:00
 * @LastEditors: SunZewen
 * @LastEditTime: 2023-06-03 13:53:22
 * @Description:   
 * @FilePath: /zwsun/workspace/iot_cloud/iot/include/bytesegment/common/data_scale.hpp
 */
#include <vector>
#include <cstdint>


int data_set_scale(std::vector<uint32_t> src, std::vector<uint32_t> &out, uint32_t scale)
{
    for(uint64_t i = 0; i < scale; i++)
    {
        for(uint64_t k = 0; k < src.size(); k++)
        {
            out.push_back(src[k]);
        }
    }

    return 0;
}


int data_set_scale(std::vector<int32_t> src, std::vector<int32_t> &out, uint32_t scale)
{
    for(uint64_t i = 0; i < scale; i++)
    {
        for(uint64_t k = 0; k < src.size(); k++)
        {
            out.push_back(src[k]);
        }
    }

    return 0;
}