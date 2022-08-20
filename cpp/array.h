#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h>
#include <string.h>

template<typename T, size_t Size>
struct Array
{
    T Data[Size];

    unsigned int ArraySize;

    T GetValueAtIndex(unsigned int index)
    {
        return this->Data[index];
    }

    T SetValueAtIndex(unsigned int index, T value)
    {
        return (this->Data[index] = value);
    }

    T operator [](unsigned int index)
    {
        return this->GetValueAtIndex(index);
    }

    T operator =(T array[])
    {
        this->ArraySize = (sizeof(array) / sizeof(T));

        memcpy(this->Data, array.Data, this->ArraySize);
    }

    T operator =(Array<T, Size>& array)
    {
        this->ArraySize = (sizeof(array) / sizeof(T));

        memcpy(this->Data, array.Data, this->ArraySize);
    }

    T operator =(Array<T, Size> array)
    {
        this->ArraySize = (sizeof(array) / sizeof(T));

        memcpy(this->Data, array.Data, this->ArraySize);
    }

    Array() : ArraySize(Size)
    {
    }

    Array(T* data)
    {
        memcpy(this->Data, data, Size);
    }

    Array(Array<T, Size>& array)
    {
        memcpy(this->Data, array.Data, Size);
    }

    ~Array()
    {
    }
};

#endif // ARRAY_H_
