#ifndef HASH_H
#define HASH_H

#include "array.h"
#include "MD5.h"

class Hash
{
public:
    static Array<char, 64> GetMD5Hash(char*);
    static Array<char, 64> GetMD5Hash(char*, size_t);
};

#endif
