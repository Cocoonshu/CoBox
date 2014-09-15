#ifndef VECTOR2_H
#define VECTOR2_H

#include "Core.h"
#include <stdio.h>

namespace CoBox {

class Vector2
{
public:
    Vector2();
    Vector2(const Vector2& vector);
    Vector2(Float vx, Float vy);
    ~Vector2();

    Float operator [] (int i) const;
    Vector2 &operator = (const Vector2& vector);

    bool operator == (const Vector2& vector) const;
    bool operator != (const Vector2& vector) const;

    Vector2 operator - () const;
    Vector2 operator + (const Vector2 &vector) const;
    Vector2 operator - (const Vector2 &vector) const;
    Vector2 operator * (const Vector2 &vector) const;
    Vector2 operator / (const Vector2 &vector) const;

    Vector2 operator += (const Vector2 &vector) const;
    Vector2 operator -= (const Vector2 &vector) const;
    Vector2 operator *= (const Vector2 &vector) const;
    Vector2 operator /= (const Vector2 &vector) const;

    Vector2 operator + (Float val) const;
    Vector2 operator - (Float val) const;
    Vector2 operator * (Float val) const;
    Vector2 operator / (Float val) const;

    Vector2 operator += (Float val) const;
    Vector2 operator -= (Float val) const;
    Vector2 operator *= (Float val) const;
    Vector2 operator /= (Float val) const;

    Float        length() const;
    void         normalize();
    Array<float> toArray() const;
    char*        toString() const;

public:
    static Float   dotProduct(const Vector2 &vectorA, const Vector2 &vectorB);
    static Vector2 crossProduct(const Vector2 &vectorA, const Vector2 &vectorB);
    static Float   distance(const Vector2 &vectorA, const Vector2 &vectorB);
    static Radian  angle(const Vector2 &vectorA, const Vector2 &vectorB);
    static int     orientations(const Vector2 &vectorA, const Vector2 &vectorB);
    static Float   length(const Vector2 &vector);
    static Float   fastNorm(const Vector2 &vector);
    static Float   norm(const Vector2 &vector);
    static Float   normalize(Vector2 &vector);

public:
    static const Vector2 Zero;
    static const Vector2 XAxis;
    static const Vector2 YAxis;
    static const Vector2 Left;
    static const Vector2 Right;
    static const Vector2 Up;
    static const Vector2 Down;

public:
    Float x, y;
};

}

#endif // VECTOR2_H
