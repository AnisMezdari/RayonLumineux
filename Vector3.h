#ifndef POINT_H
#define POINT_H

#include <iostream>


class Vector3
{
public:
    float x;
    float y;
    float z;

    Vector3(float x, float y, float z);
    float dotProduct(const Vector3 &v1) const;
    Vector3 crossProduct(const Vector3 &v1) const;
    Vector3 normalize();
    float norm();

};

Vector3 operator-(const Vector3& v);

Vector3 operator+(const Vector3& a, const Vector3& b);
Vector3 operator-(const Vector3& a, const Vector3& b);
Vector3 operator*(const Vector3& a, const Vector3& b);
Vector3 operator/(const Vector3& a, const Vector3& b);

Vector3 operator+(const Vector3& a, float scalar);
Vector3 operator-(const Vector3& a, float scalar);
Vector3 operator*(const Vector3& a, float scalar);
Vector3 operator/(const Vector3& a, float scalar);

Vector3 operator+(float scalar, const Vector3& a);
Vector3 operator-(float scalar, const Vector3& a);
Vector3 operator*(float scalar, const Vector3& a);
Vector3 operator/(float scalar, const Vector3& a);

std::ostream& operator<<(std::ostream& stream, const Vector3& v);

#endif // POINT_H
