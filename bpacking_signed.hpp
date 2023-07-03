/**
 *
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 * (c) Daniel Lemire 2013
 */

// #include "bpacking.h"
#include <cstdint>


namespace compression
{
    namespace bitpacking
    {
        namespace signed_integer
        {

            typedef uint32_t *(*packfnc)(int32_t, int32_t *, uint32_t *);

            uint32_t *nullpacker(int32_t, int32_t *, uint32_t *out)
            {
                return out;
            }

            uint32_t *pack1_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;

                return out + 1;
            }

            uint32_t *pack2_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;

                return out + 1;
            }

            uint32_t *pack3_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;

                return out + 1;
            }

            uint32_t *pack4_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack5_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (5 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;

                return out + 1;
            }

            uint32_t *pack6_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (6 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;

                return out + 1;
            }

            uint32_t *pack7_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;

                return out + 1;
            }

            uint32_t *pack8_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack9_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 8);
                ++in;

                return out + 1;
            }

            uint32_t *pack10_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;

                return out + 1;
            }

            uint32_t *pack11_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;

                return out + 1;
            }

            uint32_t *pack12_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack13_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 8);
                ++in;

                return out + 1;
            }

            uint32_t *pack14_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;

                return out + 1;
            }

            uint32_t *pack15_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;

                return out + 1;
            }

            uint32_t *pack16_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack17_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 8);
                ++in;

                return out + 1;
            }

            uint32_t *pack18_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack19_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;

                return out + 1;
            }

            uint32_t *pack20_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack21_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 8);
                ++in;

                return out + 1;
            }

            uint32_t *pack22_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack23_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;

                return out + 1;
            }

            uint32_t *pack24_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack25_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 8);
                ++in;

                return out + 1;
            }

            uint32_t *pack26_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack27_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 24);
                ++in;

                return out + 1;
            }

            uint32_t *pack28_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack29_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 23);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 8);
                ++in;

                return out + 1;
            }

            uint32_t *pack30_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack31_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 30);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 29);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 27);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 25);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 24);
                ++in;

                return out + 1;
            }

            uint32_t *pack32_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;

                return out;
            }

            int32_t *unpack1_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) & 1;
                *out += base;
                out++;
                *out = ((*in) >> 1) & 1;
                *out += base;
                out++;
                *out = ((*in) >> 2) & 1;
                *out += base;
                out++;
                *out = ((*in) >> 3) & 1;
                *out += base;
                out++;
                *out = ((*in) >> 4) & 1;
                *out += base;
                out++;
                *out = ((*in) >> 5) & 1;
                *out += base;
                out++;
                *out = ((*in) >> 6) & 1;
                *out += base;
                out++;
                *out = ((*in) >> 7) & 1;
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack2_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 2);
                *out += base;
                out++;
                *out = ((*in) >> 2) % (1U << 2);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 2);
                *out += base;
                out++;
                *out = ((*in) >> 6) % (1U << 2);
                *out += base;
                out++;
                *out = ((*in) >> 8) % (1U << 2);
                *out += base;
                out++;
                *out = ((*in) >> 10) % (1U << 2);
                *out += base;
                out++;
                *out = ((*in) >> 12) % (1U << 2);
                *out += base;
                out++;
                *out = ((*in) >> 14) % (1U << 2);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack3_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 3);
                *out += base;
                out++;
                *out = ((*in) >> 3) % (1U << 3);
                *out += base;
                out++;
                *out = ((*in) >> 6) % (1U << 3);
                *out += base;
                out++;
                *out = ((*in) >> 9) % (1U << 3);
                *out += base;
                out++;
                *out = ((*in) >> 12) % (1U << 3);
                *out += base;
                out++;
                *out = ((*in) >> 15) % (1U << 3);
                *out += base;
                out++;
                *out = ((*in) >> 18) % (1U << 3);
                *out += base;
                out++;
                *out = ((*in) >> 21) % (1U << 3);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack4_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 4);
                *out += base;
                out++;
                *out = ((*in) >> 8) % (1U << 4);
                *out += base;
                out++;
                *out = ((*in) >> 12) % (1U << 4);
                *out += base;
                out++;
                *out = ((*in) >> 16) % (1U << 4);
                *out += base;
                out++;
                *out = ((*in) >> 20) % (1U << 4);
                *out += base;
                out++;
                *out = ((*in) >> 24) % (1U << 4);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out += base;
                out++;

                return in;
            }

            int32_t *unpack5_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 5);
                *out += base;
                out++;
                *out = ((*in) >> 5) % (1U << 5);
                *out += base;
                out++;
                *out = ((*in) >> 10) % (1U << 5);
                *out += base;
                out++;
                *out = ((*in) >> 15) % (1U << 5);
                *out += base;
                out++;
                *out = ((*in) >> 20) % (1U << 5);
                *out += base;
                out++;
                *out = ((*in) >> 25) % (1U << 5);
                *out += base;
                out++;
                *out = ((*in) >> 30);
                ++in;
                *out |= ((*in) % (1U << 3)) << (5 - 3);
                *out += base;
                out++;
                *out = ((*in) >> 3) % (1U << 5);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack6_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 6);
                *out += base;
                out++;
                *out = ((*in) >> 6) % (1U << 6);
                *out += base;
                out++;
                *out = ((*in) >> 12) % (1U << 6);
                *out += base;
                out++;
                *out = ((*in) >> 18) % (1U << 6);
                *out += base;
                out++;
                *out = ((*in) >> 24) % (1U << 6);
                *out += base;
                out++;
                *out = ((*in) >> 30);
                ++in;
                *out |= ((*in) % (1U << 4)) << (6 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 6);
                *out += base;
                out++;
                *out = ((*in) >> 10) % (1U << 6);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack7_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 7);
                *out += base;
                out++;
                *out = ((*in) >> 7) % (1U << 7);
                *out += base;
                out++;
                *out = ((*in) >> 14) % (1U << 7);
                *out += base;
                out++;
                *out = ((*in) >> 21) % (1U << 7);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 3)) << (7 - 3);
                *out += base;
                out++;
                *out = ((*in) >> 3) % (1U << 7);
                *out += base;
                out++;
                *out = ((*in) >> 10) % (1U << 7);
                *out += base;
                out++;
                *out = ((*in) >> 17) % (1U << 7);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack8_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 8);
                *out += base;
                out++;
                *out = ((*in) >> 8) % (1U << 8);
                *out += base;
                out++;
                *out = ((*in) >> 16) % (1U << 8);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0) % (1U << 8);
                *out += base;
                out++;
                *out = ((*in) >> 8) % (1U << 8);
                *out += base;
                out++;
                *out = ((*in) >> 16) % (1U << 8);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out += base;
                out++;

                return in;
            }

            int32_t *unpack9_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 9);
                *out += base;
                out++;
                *out = ((*in) >> 9) % (1U << 9);
                *out += base;
                out++;
                *out = ((*in) >> 18) % (1U << 9);
                *out += base;
                out++;
                *out = ((*in) >> 27);
                ++in;
                *out |= ((*in) % (1U << 4)) << (9 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 9);
                *out += base;
                out++;
                *out = ((*in) >> 13) % (1U << 9);
                *out += base;
                out++;
                *out = ((*in) >> 22) % (1U << 9);
                *out += base;
                out++;
                *out = ((*in) >> 31);
                ++in;
                *out |= ((*in) % (1U << 8)) << (9 - 8);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack10_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 10);
                *out += base;
                out++;
                *out = ((*in) >> 10) % (1U << 10);
                *out += base;
                out++;
                *out = ((*in) >> 20) % (1U << 10);
                *out += base;
                out++;
                *out = ((*in) >> 30);
                ++in;
                *out |= ((*in) % (1U << 8)) << (10 - 8);
                *out += base;
                out++;
                *out = ((*in) >> 8) % (1U << 10);
                *out += base;
                out++;
                *out = ((*in) >> 18) % (1U << 10);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 6)) << (10 - 6);
                *out += base;
                out++;
                *out = ((*in) >> 6) % (1U << 10);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack11_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 11);
                *out += base;
                out++;
                *out = ((*in) >> 11) % (1U << 11);
                *out += base;
                out++;
                *out = ((*in) >> 22);
                ++in;
                *out |= ((*in) % (1U << 1)) << (11 - 1);
                *out += base;
                out++;
                *out = ((*in) >> 1) % (1U << 11);
                *out += base;
                out++;
                *out = ((*in) >> 12) % (1U << 11);
                *out += base;
                out++;
                *out = ((*in) >> 23);
                ++in;
                *out |= ((*in) % (1U << 2)) << (11 - 2);
                *out += base;
                out++;
                *out = ((*in) >> 2) % (1U << 11);
                *out += base;
                out++;
                *out = ((*in) >> 13) % (1U << 11);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack12_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 12);
                *out += base;
                out++;
                *out = ((*in) >> 12) % (1U << 12);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out |= ((*in) % (1U << 4)) << (12 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 12);
                *out += base;
                out++;
                *out = ((*in) >> 16) % (1U << 12);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 8)) << (12 - 8);
                *out += base;
                out++;
                *out = ((*in) >> 8) % (1U << 12);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out += base;
                out++;

                return in;
            }

            int32_t *unpack13_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 13);
                *out += base;
                out++;
                *out = ((*in) >> 13) % (1U << 13);
                *out += base;
                out++;
                *out = ((*in) >> 26);
                ++in;
                *out |= ((*in) % (1U << 7)) << (13 - 7);
                *out += base;
                out++;
                *out = ((*in) >> 7) % (1U << 13);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out |= ((*in) % (1U << 1)) << (13 - 1);
                *out += base;
                out++;
                *out = ((*in) >> 1) % (1U << 13);
                *out += base;
                out++;
                *out = ((*in) >> 14) % (1U << 13);
                *out += base;
                out++;
                *out = ((*in) >> 27);
                ++in;
                *out |= ((*in) % (1U << 8)) << (13 - 8);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack14_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 14);
                *out += base;
                out++;
                *out = ((*in) >> 14) % (1U << 14);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 10)) << (14 - 10);
                *out += base;
                out++;
                *out = ((*in) >> 10) % (1U << 14);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out |= ((*in) % (1U << 6)) << (14 - 6);
                *out += base;
                out++;
                *out = ((*in) >> 6) % (1U << 14);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out |= ((*in) % (1U << 2)) << (14 - 2);
                *out += base;
                out++;
                *out = ((*in) >> 2) % (1U << 14);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack15_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 15);
                *out += base;
                out++;
                *out = ((*in) >> 15) % (1U << 15);
                *out += base;
                out++;
                *out = ((*in) >> 30);
                ++in;
                *out |= ((*in) % (1U << 13)) << (15 - 13);
                *out += base;
                out++;
                *out = ((*in) >> 13) % (1U << 15);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 11)) << (15 - 11);
                *out += base;
                out++;
                *out = ((*in) >> 11) % (1U << 15);
                *out += base;
                out++;
                *out = ((*in) >> 26);
                ++in;
                *out |= ((*in) % (1U << 9)) << (15 - 9);
                *out += base;
                out++;
                *out = ((*in) >> 9) % (1U << 15);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack16_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 16);
                *out += base;
                out++;
                *out = ((*in) >> 16);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0) % (1U << 16);
                *out += base;
                out++;
                *out = ((*in) >> 16);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0) % (1U << 16);
                *out += base;
                out++;
                *out = ((*in) >> 16);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0) % (1U << 16);
                *out += base;
                out++;
                *out = ((*in) >> 16);
                ++in;
                *out += base;
                out++;

                return in;
            }

            int32_t *unpack17_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 17);
                *out += base;
                out++;
                *out = ((*in) >> 17);
                ++in;
                *out |= ((*in) % (1U << 2)) << (17 - 2);
                *out += base;
                out++;
                *out = ((*in) >> 2) % (1U << 17);
                *out += base;
                out++;
                *out = ((*in) >> 19);
                ++in;
                *out |= ((*in) % (1U << 4)) << (17 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 17);
                *out += base;
                out++;
                *out = ((*in) >> 21);
                ++in;
                *out |= ((*in) % (1U << 6)) << (17 - 6);
                *out += base;
                out++;
                *out = ((*in) >> 6) % (1U << 17);
                *out += base;
                out++;
                *out = ((*in) >> 23);
                ++in;
                *out |= ((*in) % (1U << 8)) << (17 - 8);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack18_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 18);
                *out += base;
                out++;
                *out = ((*in) >> 18);
                ++in;
                *out |= ((*in) % (1U << 4)) << (18 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 18);
                *out += base;
                out++;
                *out = ((*in) >> 22);
                ++in;
                *out |= ((*in) % (1U << 8)) << (18 - 8);
                *out += base;
                out++;
                *out = ((*in) >> 8) % (1U << 18);
                *out += base;
                out++;
                *out = ((*in) >> 26);
                ++in;
                *out |= ((*in) % (1U << 12)) << (18 - 12);
                *out += base;
                out++;
                *out = ((*in) >> 12) % (1U << 18);
                *out += base;
                out++;
                *out = ((*in) >> 30);
                ++in;
                *out |= ((*in) % (1U << 16)) << (18 - 16);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack19_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 19);
                *out += base;
                out++;
                *out = ((*in) >> 19);
                ++in;
                *out |= ((*in) % (1U << 6)) << (19 - 6);
                *out += base;
                out++;
                *out = ((*in) >> 6) % (1U << 19);
                *out += base;
                out++;
                *out = ((*in) >> 25);
                ++in;
                *out |= ((*in) % (1U << 12)) << (19 - 12);
                *out += base;
                out++;
                *out = ((*in) >> 12) % (1U << 19);
                *out += base;
                out++;
                *out = ((*in) >> 31);
                ++in;
                *out |= ((*in) % (1U << 18)) << (19 - 18);
                *out += base;
                out++;
                *out = ((*in) >> 18);
                ++in;
                *out |= ((*in) % (1U << 5)) << (19 - 5);
                *out += base;
                out++;
                *out = ((*in) >> 5) % (1U << 19);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack20_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 20);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out |= ((*in) % (1U << 8)) << (20 - 8);
                *out += base;
                out++;
                *out = ((*in) >> 8) % (1U << 20);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 16)) << (20 - 16);
                *out += base;
                out++;
                *out = ((*in) >> 16);
                ++in;
                *out |= ((*in) % (1U << 4)) << (20 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 20);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out |= ((*in) % (1U << 12)) << (20 - 12);
                *out += base;
                out++;
                *out = ((*in) >> 12);
                ++in;
                *out += base;
                out++;

                return in;
            }

            int32_t *unpack21_8(int32_t base, int32_t *in, uint32_t *out)
            {
                *out = ((*in) >> 0) % (1U << 21);
                *out += base;
                out++;
                *out = ((*in) >> 21);
                ++in;
                *out |= ((*in) % (1U << 10)) << (21 - 10);
                *out += base;
                out++;
                *out = ((*in) >> 10) % (1U << 21);
                *out += base;
                out++;
                *out = ((*in) >> 31);
                ++in;
                *out |= ((*in) % (1U << 20)) << (21 - 20);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out |= ((*in) % (1U << 9)) << (21 - 9);
                *out += base;
                out++;
                *out = ((*in) >> 9) % (1U << 21);
                *out += base;
                out++;
                *out = ((*in) >> 30);
                ++in;
                *out |= ((*in) % (1U << 19)) << (21 - 19);
                *out += base;
                out++;
                *out = ((*in) >> 19);
                ++in;
                *out |= ((*in) % (1U << 8)) << (21 - 8);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack22_8(int32_t base, int32_t *in, uint32_t *out)
            {
                *out = ((*in) >> 0) % (1U << 22);
                *out += base;
                out++;
                *out = ((*in) >> 22);
                ++in;
                *out |= ((*in) % (1U << 12)) << (22 - 12);
                *out += base;
                out++;
                *out = ((*in) >> 12);
                ++in;
                *out |= ((*in) % (1U << 2)) << (22 - 2);
                *out += base;
                out++;
                *out = ((*in) >> 2) % (1U << 22);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out |= ((*in) % (1U << 14)) << (22 - 14);
                *out += base;
                out++;
                *out = ((*in) >> 14);
                ++in;
                *out |= ((*in) % (1U << 4)) << (22 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 22);
                *out += base;
                out++;
                *out = ((*in) >> 26);
                ++in;
                *out |= ((*in) % (1U << 16)) << (22 - 16);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack23_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 23);
                *out += base;
                out++;
                *out = ((*in) >> 23);
                ++in;
                *out |= ((*in) % (1U << 14)) << (23 - 14);
                *out += base;
                out++;
                *out = ((*in) >> 14);
                ++in;
                *out |= ((*in) % (1U << 5)) << (23 - 5);
                *out += base;
                out++;
                *out = ((*in) >> 5) % (1U << 23);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 19)) << (23 - 19);
                *out += base;
                out++;
                *out = ((*in) >> 19);
                ++in;
                *out |= ((*in) % (1U << 10)) << (23 - 10);
                *out += base;
                out++;
                *out = ((*in) >> 10);
                ++in;
                *out |= ((*in) % (1U << 1)) << (23 - 1);
                *out += base;
                out++;
                *out = ((*in) >> 1) % (1U << 23);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack24_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 24);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out |= ((*in) % (1U << 16)) << (24 - 16);
                *out += base;
                out++;
                *out = ((*in) >> 16);
                ++in;
                *out |= ((*in) % (1U << 8)) << (24 - 8);
                *out += base;
                out++;
                *out = ((*in) >> 8);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0) % (1U << 24);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out |= ((*in) % (1U << 16)) << (24 - 16);
                *out += base;
                out++;
                *out = ((*in) >> 16);
                ++in;
                *out |= ((*in) % (1U << 8)) << (24 - 8);
                *out += base;
                out++;
                *out = ((*in) >> 8);
                ++in;
                *out += base;
                out++;

                return in;
            }

            int32_t *unpack25_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 25);
                *out += base;
                out++;
                *out = ((*in) >> 25);
                ++in;
                *out |= ((*in) % (1U << 18)) << (25 - 18);
                *out += base;
                out++;
                *out = ((*in) >> 18);
                ++in;
                *out |= ((*in) % (1U << 11)) << (25 - 11);
                *out += base;
                out++;
                *out = ((*in) >> 11);
                ++in;
                *out |= ((*in) % (1U << 4)) << (25 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4) % (1U << 25);
                *out += base;
                out++;
                *out = ((*in) >> 29);
                ++in;
                *out |= ((*in) % (1U << 22)) << (25 - 22);
                *out += base;
                out++;
                *out = ((*in) >> 22);
                ++in;
                *out |= ((*in) % (1U << 15)) << (25 - 15);
                *out += base;
                out++;
                *out = ((*in) >> 15);
                ++in;
                *out |= ((*in) % (1U << 8)) << (25 - 8);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack26_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 26);
                *out += base;
                out++;
                *out = ((*in) >> 26);
                ++in;
                *out |= ((*in) % (1U << 20)) << (26 - 20);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out |= ((*in) % (1U << 14)) << (26 - 14);
                *out += base;
                out++;
                *out = ((*in) >> 14);
                ++in;
                *out |= ((*in) % (1U << 8)) << (26 - 8);
                *out += base;
                out++;
                *out = ((*in) >> 8);
                ++in;
                *out |= ((*in) % (1U << 2)) << (26 - 2);
                *out += base;
                out++;
                *out = ((*in) >> 2) % (1U << 26);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 22)) << (26 - 22);
                *out += base;
                out++;
                *out = ((*in) >> 22);
                ++in;
                *out |= ((*in) % (1U << 16)) << (26 - 16);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack27_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 27);
                *out += base;
                out++;
                *out = ((*in) >> 27);
                ++in;
                *out |= ((*in) % (1U << 22)) << (27 - 22);
                *out += base;
                out++;
                *out = ((*in) >> 22);
                ++in;
                *out |= ((*in) % (1U << 17)) << (27 - 17);
                *out += base;
                out++;
                *out = ((*in) >> 17);
                ++in;
                *out |= ((*in) % (1U << 12)) << (27 - 12);
                *out += base;
                out++;
                *out = ((*in) >> 12);
                ++in;
                *out |= ((*in) % (1U << 7)) << (27 - 7);
                *out += base;
                out++;
                *out = ((*in) >> 7);
                ++in;
                *out |= ((*in) % (1U << 2)) << (27 - 2);
                *out += base;
                out++;
                *out = ((*in) >> 2) % (1U << 27);
                *out += base;
                out++;
                *out = ((*in) >> 29);
                ++in;
                *out |= ((*in) % (1U << 24)) << (27 - 24);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack28_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 28);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 24)) << (28 - 24);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out |= ((*in) % (1U << 20)) << (28 - 20);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out |= ((*in) % (1U << 16)) << (28 - 16);
                *out += base;
                out++;
                *out = ((*in) >> 16);
                ++in;
                *out |= ((*in) % (1U << 12)) << (28 - 12);
                *out += base;
                out++;
                *out = ((*in) >> 12);
                ++in;
                *out |= ((*in) % (1U << 8)) << (28 - 8);
                *out += base;
                out++;
                *out = ((*in) >> 8);
                ++in;
                *out |= ((*in) % (1U << 4)) << (28 - 4);
                *out += base;
                out++;
                *out = ((*in) >> 4);
                ++in;
                *out += base;
                out++;

                return in;
            }

            int32_t *unpack29_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 29);
                *out += base;
                out++;
                *out = ((*in) >> 29);
                ++in;
                *out |= ((*in) % (1U << 26)) << (29 - 26);
                *out += base;
                out++;
                *out = ((*in) >> 26);
                ++in;
                *out |= ((*in) % (1U << 23)) << (29 - 23);
                *out += base;
                out++;
                *out = ((*in) >> 23);
                ++in;
                *out |= ((*in) % (1U << 20)) << (29 - 20);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out |= ((*in) % (1U << 17)) << (29 - 17);
                *out += base;
                out++;
                *out = ((*in) >> 17);
                ++in;
                *out |= ((*in) % (1U << 14)) << (29 - 14);
                *out += base;
                out++;
                *out = ((*in) >> 14);
                ++in;
                *out |= ((*in) % (1U << 11)) << (29 - 11);
                *out += base;
                out++;
                *out = ((*in) >> 11);
                ++in;
                *out |= ((*in) % (1U << 8)) << (29 - 8);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack30_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 30);
                *out += base;
                out++;
                *out = ((*in) >> 30);
                ++in;
                *out |= ((*in) % (1U << 28)) << (30 - 28);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 26)) << (30 - 26);
                *out += base;
                out++;
                *out = ((*in) >> 26);
                ++in;
                *out |= ((*in) % (1U << 24)) << (30 - 24);
                *out += base;
                out++;
                *out = ((*in) >> 24);
                ++in;
                *out |= ((*in) % (1U << 22)) << (30 - 22);
                *out += base;
                out++;
                *out = ((*in) >> 22);
                ++in;
                *out |= ((*in) % (1U << 20)) << (30 - 20);
                *out += base;
                out++;
                *out = ((*in) >> 20);
                ++in;
                *out |= ((*in) % (1U << 18)) << (30 - 18);
                *out += base;
                out++;
                *out = ((*in) >> 18);
                ++in;
                *out |= ((*in) % (1U << 16)) << (30 - 16);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack31_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0) % (1U << 31);
                *out += base;
                out++;
                *out = ((*in) >> 31);
                ++in;
                *out |= ((*in) % (1U << 30)) << (31 - 30);
                *out += base;
                out++;
                *out = ((*in) >> 30);
                ++in;
                *out |= ((*in) % (1U << 29)) << (31 - 29);
                *out += base;
                out++;
                *out = ((*in) >> 29);
                ++in;
                *out |= ((*in) % (1U << 28)) << (31 - 28);
                *out += base;
                out++;
                *out = ((*in) >> 28);
                ++in;
                *out |= ((*in) % (1U << 27)) << (31 - 27);
                *out += base;
                out++;
                *out = ((*in) >> 27);
                ++in;
                *out |= ((*in) % (1U << 26)) << (31 - 26);
                *out += base;
                out++;
                *out = ((*in) >> 26);
                ++in;
                *out |= ((*in) % (1U << 25)) << (31 - 25);
                *out += base;
                out++;
                *out = ((*in) >> 25);
                ++in;
                *out |= ((*in) % (1U << 24)) << (31 - 24);
                *out += base;
                out++;

                return in + 1;
            }

            int32_t *unpack32_8(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = ((*in) >> 0);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0);
                ++in;
                *out += base;
                out++;
                *out = ((*in) >> 0);
                ++in;
                *out += base;
                out++;

                return in;
            }

            uint32_t *pack1_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;

                return out + 1;
            }

            uint32_t *pack2_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack3_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (3 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;

                return out + 1;
            }

            uint32_t *pack4_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack5_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (5 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (5 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;

                return out + 1;
            }

            uint32_t *pack6_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (6 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (6 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack7_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;

                return out + 1;
            }

            uint32_t *pack8_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack9_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;

                return out + 1;
            }

            uint32_t *pack10_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack11_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;

                return out + 1;
            }

            uint32_t *pack12_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack13_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;

                return out + 1;
            }

            uint32_t *pack14_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack15_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;

                return out + 1;
            }

            uint32_t *pack16_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack17_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack18_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack19_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack20_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack21_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack22_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack23_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack24_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack25_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 23);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack26_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack27_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 21);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack28_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack29_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 23);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 25);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack30_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack31_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 30);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 29);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 27);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 25);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 23);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 21);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 16);
                ++in;

                return out + 1;
            }

            uint32_t *pack32_16(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack1_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack2_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack3_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (3 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (3 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack4_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack5_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (5 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (5 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (5 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (5 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack6_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (6 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (6 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (6 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (6 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack7_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (7 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack8_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack9_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (9 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack10_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (10 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack11_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (11 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack12_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (12 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack13_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (13 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack14_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (14 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack15_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (15 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack16_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack17_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (17 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack18_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (18 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack19_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (19 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack20_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (20 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack21_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (21 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack22_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (22 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack23_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 21);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (23 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack24_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (24 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack25_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 23);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 21);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (25 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack26_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (26 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack27_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 21);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 23);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 25);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (27 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack28_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (28 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack29_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 23);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 25);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 27);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 21);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (29 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack30_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (30 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack31_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 31;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 30);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 30;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 29);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 29;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 28);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 28;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 27);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 27;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 26);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 26;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 25);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 25;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 24);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 24;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 23);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 23;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 22);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 22;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 21);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 21;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 20);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 20;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 19);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 19;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 18);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 18;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 17);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 17;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 16);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 16;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 15);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 15;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 14);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 14;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 13);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 13;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 12);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 12;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 11);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 11;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 10);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 10;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 9);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 9;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 8);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 8;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 7);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 7;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 6);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 6;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 5);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 5;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 4);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 4;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 3);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 3;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 2);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 2;
                ++out;
                *out = static_cast<uint32_t>((*in) - base) >> (31 - 1);
                ++in;
                *out |= static_cast<uint32_t>((*in) - base) << 1;
                ++out;
                ++in;

                return out;
            }

            uint32_t *pack32_32(int32_t base, int32_t *in, uint32_t *out)
            {

                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;
                *out = static_cast<uint32_t>((*in) - base);
                ++out;
                ++in;

                return out;
            }

        }
    }
}