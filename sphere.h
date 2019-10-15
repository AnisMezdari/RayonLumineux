#ifndef SPHERE_H
#define SPHERE_H
#include <Vector3.h>

class Sphere
{
    public:
        float radius;
        Vector3 center;
        Sphere(float radius, const Vector3& center);
};

#endif // SPHERE_H
