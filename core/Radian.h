#ifndef RADIAN_H
#define RADIAN_H

#include "Core.h"

namespace CoBox {

class Degree;
class Radian
{
public:
    Radian();
    Radian(Float rad);
    Radian(const Radian& rad);
    ~Radian();

    Degree getDegree();
    char  *toString() const;

public:
    static Float toDegree(Float rad);
    static Float toRadian(Float deg);

public:
    static const Float ToDegree;
    static const Float ToRadian;

public:
    Float radian;
};

}

#endif // RADIAN_H
