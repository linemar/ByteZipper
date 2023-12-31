#ifndef BLOCK
#define BLOCK

#include <vector>
#include <cstdint>
#include <cstddef>

typedef bool mask;

namespace bytesegment
{
    namespace integer32
    {
        struct Block
        {
        };

        struct Block_D16U_NP_P : public Block
        {
            uint16_t * comp_data;
        };

        struct Block_D8U_P8UP : public Block
        {
            uint16_t pack_data_size = 0;
            mask * bmask;
            uint8_t * comp_data;
            uint8_t * pack_data;
        };

        struct Block_D32U : public Block
        {
            uint8_t bit_len;
            uint32_t * data;
        };
    }
}

#endif
