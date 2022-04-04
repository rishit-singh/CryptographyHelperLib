#include "hash.h"

Array<char, 64> Hash::GetMD5Hash(char* bytes)
{
    return Hash::GetMD5Hash(bytes, strlen(bytes));
}

Array<char, 64> Hash::GetMD5Hash(char* bytes, size_t size)
{
    Array<char, 64> hashedBytes;

    return hashedBytes;
}
