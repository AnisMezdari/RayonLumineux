#include "Vector3.h"
#include <math.h>

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}


float Vector3::dotProduct(const Vector3 &v1) const {
   return  (this->x * v1.x ) + (this->y * v1.y) + (this->z * v1.z);
}


Vector3 Vector3::crossProduct(const Vector3 &v1) const {
    return Vector3((this->y * v1.z) - (this->z * v1.y),
                   (this->z * v1.x) - (this->x * v1.z),
                   (this->x * v1.y) - (this->y * v1.x));
}

Vector3 Vector3::normalize(){
    float n = norm();
    return (*this) / n;
}

float Vector3::norm(){
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z) );
}

Vector3 operator-(const Vector3& v) { return Vector3(-v.x, -v.y, -v.z); }

Vector3 operator+(const Vector3& a, const Vector3& b) { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); }
Vector3 operator-(const Vector3& a, const Vector3& b) { return Vector3(a.x - b.x, a.y - b.y, a.z - b.z); }
Vector3 operator*(const Vector3& a, const Vector3& b) { return Vector3(a.x * b.x, a.y * b.y, a.z * b.z); }
Vector3 operator/(const Vector3& a, const Vector3& b) { return Vector3(a.x / b.x, a.y / b.y, a.z / b.z); }

Vector3 operator+(const Vector3& a, float scalar) { return Vector3(a.x + scalar, a.y + scalar, a.z + scalar); }
Vector3 operator-(const Vector3& a, float scalar) { return Vector3(a.x - scalar, a.y - scalar, a.z - scalar); }
Vector3 operator*(const Vector3& a, float scalar) { return Vector3(a.x * scalar, a.y * scalar, a.z * scalar); }
Vector3 operator/(const Vector3& a, float scalar) { return Vector3(a.x / scalar, a.y / scalar, a.z / scalar); }

Vector3 operator+(float scalar, const Vector3& a) { return a + scalar; }
Vector3 operator-(float scalar, const Vector3& a) { return -a + scalar; }
Vector3 operator*(float scalar, const Vector3& a) { return a * scalar; }
Vector3 operator/(float scalar, const Vector3& a) { return a / scalar; }

std::ostream& operator<<(std::ostream& stream, const Vector3& v)
{
    stream << "Vector3(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}
