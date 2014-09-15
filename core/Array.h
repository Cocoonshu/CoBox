#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"
#include <stdio.h>

namespace CoBox {

template<class T>
class Array
{
public:

    Array(size_t size);
    Array(const Array &array);
    ~Array();

    T &operator [] (size_t index) const;

    size_t length() const;
    void   clear();

private:
    T*     mpArray;
    size_t mLength;
};

}
#endif // ARRAY_H
