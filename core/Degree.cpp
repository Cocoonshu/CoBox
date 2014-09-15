#include "Degree.h"

using namespace CoBox;

const Float Radian::ToDegree = 180.0 / PI;
const Float Radian::ToRadian = PI / 180.0;

Degree::Degree()
{
}

Degree::Degree(float deg) :
    degree(deg)
{

}

Degree::Degree(const Degree &deg) :
    degree(deg.degree)
{

}

Radian Degree::getRadian()
{
    return Radian(degree * ToRadian);
}

char *Degree::toString() const
{
#ifdef HIGH_PRECISION
    char *disp = new char[16];
    sprintf(disp, "deg(%.4lf)", degree);
    disp[15] = '\0';
#else
    char *disp = new char[32];
    sprintf(disp, "deg(%.4f)", degree);
    disp[31] = '\0';
#endif

    return disp;
}

float Degree::toDegree(float rad)
{
    return rad * ToDegree;
}

float Degree::toRadian(float deg)
{
    return deg * ToRadian;
}
