#include <iostream>
#include "hash.h"

int main()
{
    char x = 0b1, y = 0b1;

    AppendBits(x, y, 1);

    std::cout << (int)x << std::endl;

    return 0;
}
