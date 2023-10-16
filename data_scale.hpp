
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
