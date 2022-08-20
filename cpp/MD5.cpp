#include "MD5.h"

#include <iostream>

void AppendBits(char& byte, char byte1, uint8_t count)
{
    byte <<= count;
    byte |= byte1;
}

void AppendBits(char* byteArray, char byte, size_t arrayCount, uint8_t shiftCount)
{
    for (int x = 0; x < arrayCount; x++)
    {
        byteArray[x] <<= shiftCount;
        byteArray[x] |= byte;
    }
}

void LeftRotate(char& byte, unsigned int count)
{
    byte = (byte << count) | (byte >> (32 - count));
}
