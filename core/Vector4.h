#ifndef VECTOR4_H
#define VECTOR4_H

#include "Core.h"

namespace CoBox {

class Vector2;
class Vector3;
class Vector4
{
public:
    Vector4();
    Vector4(const Vector2& vector);
    Vector4(const Vector3& vector);
    Vector4(const Vector4& vector);
    Vector4(Float vx = 0, Float vy = 0, Float vz = 0, Float vw = 1);
    ~Vector4();

    Float   operator [] (int i) const;
    Vector4 &operator = (const Vector4& vector);

    bool operator == (const Vector4& vector) const;
    bool operator != (const Vector4& vector) const;

    Vector4 operator - () const;
    Vector4 operator + (const Vector4 &vector) const;
    Vector4 operator - (const Vector4 &vector) const;
    Vector4 operator * (const Vector4 &vector) const;
    Vector4 operator / (const Vector4 &vector) const;

    Vector4 operator += (const Vector4 &vector) const;
    Vector4 operator -= (const Vector4 &vector) const;
    Vector4 operator *= (const Vector4 &vector) const;
    Vector4 operator /= (const Vector4 &vector) const;

    Vector4 operator + (Float val) const;
    Vector4 operator - (Float val) const;
    Vector4 operator * (Float val) const;
    Vector4 operator / (Float val) const;

    Vector4 operator += (Float val) const;
    Vector4 operator -= (Float val) const;
    Vector4 operator *= (Float val) const;
    Vector4 operator /= (Float val) const;

    Float        length() const;
    void         normalize();
    bool         unified();
    Array<float> toArray() const;
    char*        toString() const;

public:
    static Float   dotProduct(const Vector4 &vectorA, const Vector4 &vectorB);
    static Vector4 crossProduct(const Vector4 &vectorA, const Vector4 &vectorB);
    static Float   distance(const Vector4 &vectorA, const Vector4 &vectorB);
    static Radian  angle(const Vector4 &vectorA, const Vector4 &vectorB);
    static int     orientations(const Vector4 &vectorA, const Vector4 &vectorB);
    static Float   length(const Vector4 &vector);
    static Float   fastNorm(const Vector4 &vector);
    static Float   norm(const Vector4 &vector);

public:
    static const Vector4 Zero;
    static const Vector4 XAxis;
    static const Vector4 YAxis;
    static const Vector4 ZAxis;
    static const Vector4 Left;
    static const Vector4 Right;
    static const Vector4 Up;
    static const Vector4 Down;
    static const Vector4 Front;
    static const Vector4 Back;

public:
    Float x, y, z, w;
};

}

#endif // VECTOR4_H
