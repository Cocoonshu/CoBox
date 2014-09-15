#include "Vector4.h"

using namespace CoBox;

const Vector4 Vector4::Zero  = Vector4(0, 0, 0, 1);
const Vector4 Vector4::XAxis = Vector4(1, 0, 0, 1);
const Vector4 Vector4::YAxis = Vector4(0, 1, 0, 1);
const Vector4 Vector4::ZAxis = Vector4(0, 0, 1, 1);
const Vector4 Vector4::Left  = Vector4(-1, 0, 0, 1);
const Vector4 Vector4::Right = Vector4(1, 0, 0, 1);
const Vector4 Vector4::Up    = Vector4(0, 1, 0, 1);
const Vector4 Vector4::Down  = Vector4(0, -1, 0, 1);
const Vector4 Vector4::Front = Vector4(0, 0, 1, 1);
const Vector4 Vector4::Back  = Vector4(0, 0, -1, 1);

Vector4::Vector4() :
    x(0),
    y(0),
    z(0),
    w(1)
{
}

Vector4::Vector4(const Vector2 &vector) :
    x(vector.x),
    y(vector.y),
    z(0),
    w(1)
{

}

Vector4::Vector4(const Vector3 &vector) :
    x(vector.x),
    y(vector.y),
    z(vector.z),
    w(1)
{

}

Vector4::Vector4(const Vector4 &vector) :
    x(vector.x),
    y(vector.y),
    z(vector.z),
    w(vector.w)
{

}

Vector4::Vector4(float vx, float vy, float vz, float vw) :
    x(vx),
    y(vy),
    z(vz),
    w(vw)
{

}

Float Vector4::operator [] (int i) const
{
    if (i < 0 || i > 3)
    {
        throw new IndexOutOfBoundsException();
    }
    else
    {
        return i == 0 ? x :
                        i == 1 ? y :
                                 i == 2 ? z : w;
    }
}

Vector4 &Vector4::operator =(const Vector4 &vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
    w = vector.w;
    return *this;
}

bool Vector4::operator ==(const Vector4 &vector) const
{
    return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
}

bool Vector4::operator !=(const Vector4 &vector) const
{
    return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
}

Vector4 Vector4::operator -() const
{
    return Vector4(-x, -y, -z, w);
}

Vector4 Vector4::operator +(const Vector4 &vector) const
{
    Vector4 me(*this);
    if (me.unified())
    {
        if (isNotEqual(vector.w, 0))
        {
            if (isNotEqual(vector.w, 1))
            {
                return Vector4(
                            me.x + vector.x / vector.w,
                            me.y + vector.y / vector.y,
                            me.z + vector.z / vector.z,
                            1);
            }
            else
            {
                return Vector4(
                            me.x + vector.x,
                            me.y + vector.y,
                            me.z + vector.z,
                            1);
            }
        }
    }
    else
    {
        if (isEqual(vector.w, 0))
        {
            return Vector4(
                        me.x + vector.x,
                        me.y + vector.y,
                        me.z + vector.z,
                        0);
        }
    }
}

Vector4 Vector4::operator -(const Vector4 &vector) const
{
    Vector4 me(*this);
    if (me.unified())
    {
        if (isNotEqual(vector.w, 0))
        {
            if (isNotEqual(vector.w, 1))
            {
                return Vector4(
                            me.x - vector.x / vector.w,
                            me.y - vector.y / vector.y,
                            me.z - vector.z / vector.z,
                            1);
            }
            else
            {
                return Vector4(
                            me.x - vector.x,
                            me.y - vector.y,
                            me.z - vector.z,
                            1);
            }
        }
    }
    else
    {
        if (isEqual(vector.w, 0))
        {
            return Vector4(
                        me.x - vector.x,
                        me.y - vector.y,
                        me.z - vector.z,
                        0);
        }
    }
}

bool Vector4::unified()
{
    if (isNotEqual(w, 0))
    {
        Float scalar = 1.0 / w;
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w  = 1;
        return true;
    }
    else
    {
        return false;
    }
}
