#ifndef VECTOR3_H
#define VECTOR3_H

#include "Core.h"

namespace CoBox {

class Vector2;
class Vector4;
class Vector3
{
public:
    Vector3();
    Vector3(const Vector2& vector);
    Vector3(const Vector3& vector);
    Vector3(const Vector4& vector);
    Vector3(Float vx = 0, Float vy = 0, Float vz = 0);
    ~Vector3();

    Float   operator [] (int i) const;
    Vector3 &operator = (const Vector3& vector);

    bool operator == (const Vector3& vector) const;
    bool operator != (const Vector3& vector) const;

    Vector3 operator - () const;
    Vector3 operator + (const Vector3 &vector) const;
    Vector3 operator - (const Vector3 &vector) const;
    Vector3 operator * (const Vector3 &vector) const;
    Vector3 operator / (const Vector3 &vector) const;

    Vector3 operator += (const Vector3 &vector) const;
    Vector3 operator -= (const Vector3 &vector) const;
    Vector3 operator *= (const Vector3 &vector) const;
    Vector3 operator /= (const Vector3 &vector) const;

    Vector3 operator + (Float val) const;
    Vector3 operator - (Float val) const;
    Vector3 operator * (Float val) const;
    Vector3 operator / (Float val) const;

    Vector3 operator += (Float val) const;
    Vector3 operator -= (Float val) const;
    Vector3 operator *= (Float val) const;
    Vector3 operator /= (Float val) const;

    Float        length() const;
    void         normalize();
    Array<float> toArray() const;
    char*        toString() const;

public:
    static Float   dotProduct(const Vector3 &vectorA, const Vector3 &vectorB);
    static Vector3 crossProduct(const Vector3 &vectorA, const Vector3 &vectorB);
    static Float   distance(const Vector3 &vectorA, const Vector3 &vectorB);
    static Radian  angle(const Vector3 &vectorA, const Vector3 &vectorB);
    static int     orientations(const Vector3 &vectorA, const Vector3 &vectorB);
    static Float   length(const Vector3 &vector);
    static Float   fastNorm(const Vector3 &vector);
    static Float   norm(const Vector3 &vector);
    static Float   normalize(Vector3 &vector);

public:
    static const Vector3 Zero;
    static const Vector3 XAxis;
    static const Vector3 YAxis;
    static const Vector3 ZAxis;
    static const Vector3 Left;
    static const Vector3 Right;
    static const Vector3 Up;
    static const Vector3 Down;
    static const Vector3 Front;
    static const Vector3 Back;

public:
    Float x, y, z;
};

}

#endif // VECTOR3_H
