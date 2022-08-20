#include <iostream>
#include "hash.h"

void PrintArray(HashedBytes64&);

void PrintArray(HashedBytes64& bytes)
{
    for (int x = 0; x < bytes.ArraySize; x++)
        std::wcout << bytes[x];

    std::cout << std::endl;
}


int main()
{
    MD5Hasher<64> hasher = MD5Hasher<64>();

    hasher.Hash("ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\x7f\dsf4");
    HashedBytes64 hashedBytes = hasher.GetFinalHash();

    PrintArray(hashedBytes);

    return 0;
}
