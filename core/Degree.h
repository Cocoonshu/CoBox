#ifndef DEGREE_H
#define DEGREE_H

#include "Core.h"

namespace CoBox {

class Radian;
class Degree
{
public:
    Degree();
    Degree(Float deg);
    Degree(const Degree& deg);
    ~Degree();

    Radian getRadian();
    char  *toString() const;

public:
    static Float toDegree(Float rad);
    static Float toRadian(Float deg);

public:
    static const Float ToDegree;
    static const Float ToRadian;

public:
    Float degree;
};

}

#endif // DEGREE_H
