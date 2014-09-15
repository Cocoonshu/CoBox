#include "Vector2.h"

using namespace CoBox;

const Vector2 Vector2::Zero  = Vector2(0, 0);
const Vector2 Vector2::XAxis = Vector2(1, 0);
const Vector2 Vector2::YAxis = Vector2(0, 1);
const Vector2 Vector2::Left  = Vector2(-1, 0);
const Vector2 Vector2::Right = Vector2(1, 0);
const Vector2 Vector2::Up    = Vector2(0, 1);
const Vector2 Vector2::Down  = Vector2(0, -1);

Vector2::Vector2() :
    x(0),
    y(0)
{

}

Vector2::Vector2(const Vector2 &vector) :
    x(vector.x),
    y(vector.y)
{

}

Vector2::Vector2(float vx, float vy) :
    x(vx),
    y(vy)
{

}

Vector2::~Vector2()
{

}

Float Vector2::operator [] (int i) const
{
    if (i < 0 || i > 1)
    {
        throw new IndexOutOfBoundsException();
    }
    else
    {
        return i == 0 ? x : y;
    }
}

Vector2 &Vector2::operator =(const Vector2 &vector)
{
    x = vector.x;
    y = vector.y;
    return *this;
}

bool Vector2::operator ==(const Vector2 &vector) const
{
    return x == vector.x && y == vector.y;
}

bool Vector2::operator !=(const Vector2 &vector) const
{
    return x != vector.x || y != vector.y;
}

Vector2 Vector2::operator -() const
{
    return Vector2(-x, -y);
}

Vector2 Vector2::operator +(const Vector2 &vector) const
{
    return Vector2(x + vector.x, y + vector.y);
}

Vector2 Vector2::operator -(const Vector2 &vector) const
{
    return Vector2(x - vector.x, y - vector.y);
}

Vector2 Vector2::operator *(const Vector2 &vector) const
{
    return Vector2(x * vector.x, y * vector.y);
}

Vector2 Vector2::operator /(const Vector2 &vector) const
{
    Float normedVector[2];
    normedVector[0] = vector.x == 0 ? ZERO : vector.x;
    normedVector[1] = vector.y == 0 ? ZERO : vector.y;
    return Vector2(x / normedVector[0], y / normedVector[1]);
}

Vector2 Vector2::operator +=(const Vector2 &vector) const
{
    return Vector2(x + vector.x, y + vector.y);
}

Vector2 Vector2::operator -=(const Vector2 &vector) const
{

    return Vector2(x - vector.x, y - vector.y);
}

Vector2 Vector2::operator *=(const Vector2 &vector) const
{
    return Vector2(x * vector.x, y * vector.y);
}

Vector2 Vector2::operator /=(const Vector2 &vector) const
{
    Float normedVector[2];
    normedVector[0] = vector.x == 0 ? ZERO : vector.x;
    normedVector[1] = vector.y == 0 ? ZERO : vector.y;
    return Vector2(x / normedVector[0], y / normedVector[1]);
}

Vector2 Vector2::operator +(float val) const
{
    return Vector2(x + val, y + val);
}

Vector2 Vector2::operator -(float val) const
{
    return Vector2(x - val, y - val);
}

Vector2 Vector2::operator *(float val) const
{
    return Vector2(x * val, y * val);
}

Vector2 Vector2::operator /(float val) const
{
    val = val == 0 ? ZERO : val;
    Float factor = ONE / val;
    return Vector2(x / factor, y / factor);
}

Vector2 Vector2::operator +=(float val) const
{
    return Vector2(x + val, y + val);
}

Vector2 Vector2::operator -=(float val) const
{
    return Vector2(x - val, y - val);
}

Vector2 Vector2::operator *=(float val) const
{
    return Vector2(x * val, y * val);
}

Vector2 Vector2::operator /=(float val) const
{
    val = val == 0 ? ZERO : val;
    Float factor = ONE / val;
    return Vector2(x / factor, y / factor);
}

Float Vector2::length() const
{
    return sqrt(x * x + y * y);
}

void Vector2::normalize()
{
    if (x != 0 && y != 0)
    {
        Float length = this->length();
        x /= length;
        y /= length;
    }
}

Array<Float> Vector2::toArray() const
{
    Array<Float> result(2);
    result[0] = x;
    result[1] = y;
    return result;
}

char *Vector2::toString() const
{
#ifdef HIGH_PRECISION
    char* disp = new char[32];
    sprintf(disp, "(%.4lf, %.4lf)", x, y);
    disp[31] = '\0';
#else
    char* disp = new char[64];
    sprintf(disp, "(%.4f, %.4f)", x, y);
    disp[63] = '\0';
#endif

    return disp;
}

float Vector2::dotProduct(const Vector2 &vectorA, const Vector2 &vectorB)
{
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y;
}

Vector2 Vector2::crossProduct(const Vector2 &, const Vector2 &)
{
    // Notice 垂直于两个二维向量的向量为零向量
    return Vector2::Zero;
}

float Vector2::distance(const Vector2 &vectorA, const Vector2 &vectorB)
{
    return sqrt(
                (Float)pow(vectorA.x - vectorB.x, 2.0) +
                (Float)pow(vectorA.y - vectorB.y, 2.0));
}

Radian Vector2::angle(const Vector2 &vectorA, const Vector2 &vectorB)
{
    Float vecALength = vectorA.length();
    if (vecALength == 0)
        return 0;

    Float vecBLength = vectorB.length();
    if (vecBLength == 0)
        return 0;

    Float numerator   = vectorA.x * vectorB.x + vectorA.y * vectorB.y;
    Float denominator = vecALength * vecBLength;
    return Radian(acos(numerator / denominator));
}

int Vector2::orientations(const Vector2 &vectorA, const Vector2 &vectorB)
{
    Float angleFactor = Vector2::dotProduct(vectorA, vectorB);
    if (angleFactor > 0)
        return 1;
    else if (angleFactor < 0)
        return -1;
    else
        return 0;
}

float Vector2::length(const Vector2 &vector)
{
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

float Vector2::fastNorm(const Vector2 &vector)
{
    return vector.x * vector.x +
           vector.y * vector.y;
}

float Vector2::norm(const Vector2 &vector)
{
    return vector.length();
}

float Vector2::normalize(Vector2 &vector)
{
    if (vector.x != 0 && vector.y != 0)
    {
        Float length = vector.length();
        vector.x /= length;
        vector.y /= length;
        return length;
    }
    else
    {
        return 0;
    }
}
