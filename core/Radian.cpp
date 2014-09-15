#include "Radian.h"

using namespace CoBox;

const Float Radian::ToDegree = 180.0 / PI;
const Float Radian::ToRadian = PI / 180.0;

Radian::Radian()
{
}

Radian::Radian(float rad) :
    radian(rad)
{

}

Radian::Radian(const Radian &rad) :
    radian(rad.radian)
{

}

Radian::~Radian()
{

}

Degree Radian::getDegree()
{
    return Degree(radian * ToDegree);
}

char *Radian::toString() const
{
#ifdef HIGH_PRECISION
    char *disp = new char[16];
    sprintf(disp, "rad(%.4lf)", radian);
    disp[15] = '\0';
#else
    char *disp = new char[32];
    sprintf(disp, "rad(%.4f)", radian);
    disp[31] = '\0';
#endif

    return disp;
}

float Radian::toDegree(float rad)
{
    return rad * ToDegree;
}

float Radian::toRadian(float deg)
{
    return deg * ToRadian;
}
