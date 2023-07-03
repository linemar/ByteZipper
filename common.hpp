/*
 * @Author: SunZewen
 * @Date: 2022-10-24 15:07:51
 * @LastEditors: SunZewen
 * @LastEditTime: 2023-06-05 18:23:29
 * @Description:
 * @FilePath: /zwsun/workspace/iot_cloud/iot/common.hpp
 */
#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cmath>


uint64_t covertfloat2uint32(float * in, uint32_t * out, uint32_t scale, uint64_t size)
{
    uint32_t scale_10 = pow(10, scale);

    for(size_t i = 0; i < size; i++)
    {
        out[i] = (uint32_t)(in[i] * scale_10);
    }

    return 0;
}


uint64_t covertfloat2int32(float * in, int32_t * out, uint32_t scale, uint64_t size)
{
    float scale_10 = pow(10, scale);
    
    for(size_t i = 0; i < size; i++)
    {
        out[i] = (int32_t)(in[i] * scale_10);
    }

    return 0;
}
