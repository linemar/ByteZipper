
#ifndef BTTE_SEGMENT_FUNC
#define BTTE_SEGMENT_FUNC

#include <vector>
#include <string>
#include <cstdint>


inline uint32_t get_min(const uint32_t *src, const size_t len)
{
    min = src[0];
    for (size_t i = 0; i < len; i++)
    {
        if (src[i] < min)
            min = src[i];
    }

    return min;
}

inline uint32_t get_max_min(const int32_t *src, const size_t len, int32_t &max, int32_t &min)
{
    min = src[0];
    max = src[0];

    for (size_t i = 1; i < len; i++)
    {
        if (src[i] < min)
            min = src[i];

        if (src[i] > max)
            max = src[i];
    }

    return 0;
}

inline uint32_t get_min(const int32_t *src, const size_t len, int32_t &min)
{
    min = src[0];
    for (size_t i = 1; i < len; i++)
    {
        if (src[i] < min)
            min = src[i];
    }

    return 0;
}
#endif
