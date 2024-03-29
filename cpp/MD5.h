#ifndef MD5_H
#define MD5_H

#include "array.h"
#include <inttypes.h>

typedef Array<char, 64> HashedBytes64;

void AppendBits(char&, char, uint8_t);
void AppendBits(char*, char, size_t, uint8_t);

void LeftRotate(char&);

template<size_t Size>
class MD5Hasher
{
private:
    static constexpr unsigned int ShiftAmounts[64] = {
        7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
        5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
        4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
        6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
    };

    static constexpr unsigned int SinValues[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };

    static constexpr unsigned int ChunkHashValues[4] = {
        0x67452301,  // A
        0xefcdab89,  // B
        0x98badcfe,  // C
        0x10325476   // D
    };

    HashedBytes64 FinalHash { HashedBytes64() };

    static char F(unsigned int, unsigned int, unsigned int);
    static char G(unsigned int, unsigned int, unsigned int);
    static char H(unsigned int, unsigned int, unsigned int);
    static char I(unsigned int, unsigned int, unsigned int);

    static constexpr char (*Operations[4])(unsigned int, unsigned int, unsigned int) = {
        MD5Hasher::F, MD5Hasher::G, MD5Hasher::H, MD5Hasher::I
    };

    static constexpr Array<char, 64> GetPaddedBytes(char* bytes)
    {
        Array<char, 64> paddedBytes = Array<char, 64>();

        int bitSize = 8;

        memcpy(paddedBytes.Data, bytes, Size);

        AppendBits(paddedBytes.Data, 0b1, Size, 1);

        for (int x = 0;  512 % bitSize != 448 && x <= Size; x++)
        {
            AppendBits(paddedBytes.Data[x], 0b0, 1);

            paddedBytes.SetValueAtIndex(x, paddedBytes.Data[x]);

            bitSize += 8;
        }

        return paddedBytes;
    }


    unsigned int ContextBitSize = Size * 8;

public:
    HashedBytes64 Hash(char* bytes)
    {
        this->FinalHash = MD5Hasher::GetPaddedBytes(bytes);

        return this->FinalHash;
    }

    HashedBytes64 GetFinalHash()
    {
        return this->FinalHash;
    }
};

#endif // MD5_H_
