#include "Array.h"

using namespace CoBox;

template<class T>
Array<T>::Array(size_t size)
{
    mpArray = (T*)malloc(size * sizeof(T));
    mLength = size;
}

template<class T>
Array<T>::Array(const Array &array)
{
    mpArray = (T*)malloc(array.mLength * sizeof(T));
    mLength = array.mLength;
    memcpy(this->mpArray, array.mpArray, mLength);
}

template<class T>
Array<T>::~Array()
{
    clear();
}

template<class T>
T &Array<T>::operator [](size_t index) const
{
    if (index < 0 || index >= mLength)
    {
        throw new IndexOutOfBoundsException();
    }
    else
    {
        return *(mpArray + index);
    }
}

template<class T>
size_t Array<T>::length() const
{
    return mLength;
}

template<class T>
void Array<T>::clear()
{
    mLength = 0;
    if (mpArray != NULL)
    {
        free(mpArray);
        mpArray = NULL;
    }
}
