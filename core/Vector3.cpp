#include "Vector3.h"

using namespace CoBox;

const Vector3 Vector3::Zero  = Vector3(0, 0, 0);
const Vector3 Vector3::XAxis = Vector3(1, 0, 0);
const Vector3 Vector3::YAxis = Vector3(0, 1, 0);
const Vector3 Vector3::ZAxis = Vector3(0, 0, 1);
const Vector3 Vector3::Left  = Vector3(-1, 0, 0);
const Vector3 Vector3::Right = Vector3(1, 0, 0);
const Vector3 Vector3::Up    = Vector3(0, 1, 0);
const Vector3 Vector3::Down  = Vector3(0, -1, 0);
const Vector3 Vector3::Front = Vector3(0, 0, 1);
const Vector3 Vector3::Back  = Vector3(0, 0, -1);

Vector3::Vector3() :
    x(0),
    y(0),
    z(0)
{
}

Vector3::Vector3(const Vector2 &vector) :
    x(vector.x),
    y(vector.y),
    z(0)
{

}

Vector3::Vector3(const Vector3 &vector) :
    x(vector.x),
    y(vector.y),
    z(vector.z)
{

}

Vector3::Vector3(const Vector4 &vector) :
    x(vector.x / vector.w),
    y(vector.y / vector.w),
    z(vector.z / vector.w)
{

}

Vector3::Vector3(float vx, float vy, float vz) :
    x(vx),
    y(vy),
    z(vz)
{

}

Vector3::~Vector3()
{

}

Float Vector3::operator [] (int i) const
{
    if (i < 0 || i > 2)
    {
        throw new IndexOutOfBoundsException();
    }
    else
    {
        return i == 0 ? x :
                        i == 1 ? y : z;
    }
}

Vector3 &Vector3::operator =(const Vector3 &vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}

bool Vector3::operator ==(const Vector3 &vector) const
{
    return x == vector.x && y == vector.y && z == vector.z;
}

bool Vector3::operator !=(const Vector3 &vector) const
{
    return x != vector.x || y != vector.y || z != vector.z;
}

Vector3 Vector3::operator -() const
{
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator +(const Vector3 &vector) const
{
    return Vector3(x + vector.x, y + vector.y, z + vector.z);
}

Vector3 Vector3::operator -(const Vector3 &vector) const
{
    return Vector3(x - vector.x, y - vector.y, z - vector.z);
}

Vector3 Vector3::operator *(const Vector3 &vector) const
{
    return Vector3(x * vector.x, y * vector.y, z * vector.z);
}

Vector3 Vector3::operator /(const Vector3 &vector) const
{
    Float normedVector[3];
    normedVector[0] = vector.x == 0 ? ZERO : vector.x;
    normedVector[1] = vector.y == 0 ? ZERO : vector.y;
    normedVector[2] = vector.z == 0 ? ZERO : vector.z;
    return Vector3(x / normedVector[0], y / normedVector[1], z / normedVector[2]);
}

Vector3 Vector3::operator +=(const Vector3 &vector) const
{
    return Vector3(x + vector.x, y + vector.y, z + vector.z);
}

Vector3 Vector3::operator -=(const Vector3 &vector) const
{
    return Vector3(x - vector.x , y - vector.y, z - vector.z);
}

Vector3 Vector3::operator *=(const Vector3 &vector) const
{
    return Vector3(x * vector.x, y * vector.y, z * vector.z);
}

Vector3 Vector3::operator /=(const Vector3 &vector) const
{
    Float normedVector[3];
    normedVector[0] = vector.x == 0 ? ZERO : vector.x;
    normedVector[1] = vector.y == 0 ? ZERO : vector.y;
    normedVector[2] = vector.z == 0 ? ZERO : vector.z;
    return Vector3(x / normedVector[0], y / normedVector[1], z / normedVector[2]);
}

Vector3 Vector3::operator +(float val) const
{
    return Vector3(x + val, y + val, z + val);
}

Vector3 Vector3::operator -(float val) const
{
    return Vector3(x - val, y - val, z - val);
}

Vector3 Vector3::operator *(float val) const
{
    return Vector3(x * val, y * val, z * val);
}

Vector3 Vector3::operator /(float val) const
{
    val = val == 0 ? ZERO : val;
    Float factor = ONE / val;
    return Vector3(x / factor, y / factor, z / factor);
}

Vector3 Vector3::operator +=(float val) const
{
    return Vector3(x + val, y + val, z + val);
}

Vector3 Vector3::operator -=(float val) const
{
    return Vector3(x - val, y - val, z - val);
}

Vector3 Vector3::operator *=(float val) const
{
    return Vector3(x * val, y * val, z * val);
}

Vector3 Vector3::operator /=(float val) const
{
    val = val == 0 ? ZERO : val;
    Float factor = ONE / val;
    return Vector3(x / factor, y / factor, z / factor);
}

Float Vector3::length() const
{
    return sqrt(x * x + y * y + z * z);
}

void Vector3::normalize()
{
    if (x != 0 && y != 0 && z != 0)
    {
        Float length = this->length();
        x /= length;
        y /= length;
        z /= length;
    }
}

Array<Float> Vector3::toArray() const
{
    Array<Float> result(3);
    result[0] = x;
    result[1] = y;
    result[2] = z;
    return result;
}

char *Vector3::toString() const
{
#ifdef HIGH_PRECISION
    char* disp = new char[32];
    sprintf(disp, "(%.4lf, %.4lf, %.4f)", x, y, z);
    disp[31] = '\0';
#else
    char* disp = new char[64];
    sprintf(disp, "(%.4f, %.4f, %.4f)", x, y, z);
    disp[63] = '\0';
#endif

    return disp;
}

float Vector3::dotProduct(const Vector3 &vectorA, const Vector3 &vectorB)
{
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
}

Vector3 Vector3::crossProduct(const Vector3 &vectorA, const Vector3 &vectorB)
{
    return Vector3(
                vectorA.y * vectorB.z - vectorA.z * vectorB.y,
                vectorA.z * vectorB.x - vectorA.x * vectorB.z,
                vectorA.x * vectorB.y - vectorA.y * vectorB.x);
}

Float Vector3::distance(const Vector3 &vectorA, const Vector3 &vectorB)
{
    return sqrt(
                (Float)pow(vectorA.x - vectorB.x, 2.0) +
                (Float)pow(vectorA.y - vectorB.y, 2.0) +
                (Float)pow(vectorA.z - vectorB.z, 2.0));
}

Radian Vector3::angle(const Vector3 &vectorA, const Vector3 &vectorB)
{
    Float vecALength = vectorA.length();
    if (vecALength == 0)
        return 0;

    Float vecBLength = vectorB.length();
    if (vecBLength == 0)
        return 0;

    Float numerator   = vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z;
    Float denominator = vecALength * vecBLength;
    return Radian(acos(numerator / denominator));
}

int Vector3::orientations(const Vector3 &vectorA, const Vector3 &vectorB)
{
    Float angleFactor = Vector3::dotProduct(vectorA, vectorB);
    if (angleFactor > 0)
        return 1;
    else if (angleFactor < 0)
        return -1;
    else
        return 0;
}

Float Vector3::length(const Vector3 &vector)
{
    return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

Float Vector3::fastNorm(const Vector3 &vector)
{
    return vector.x * vector.x +
           vector.y * vector.y +
           vector.z * vector.z;
}

Float Vector3::norm(const Vector3 &vector)
{
    return vector.length();
}

float Vector3::normalize(Vector3 &vector)
{
    if (vector.x != 0 && vector.y != 0 && vector.z != 0)
    {
        Float length = vector.length();
        vector.x /= length;
        vector.y /= length;
        vector.z /= length;
        return length;
    }
    else
    {
        return 0;
    }
}


