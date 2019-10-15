#ifndef RAYONLUMINEUX_H
#define RAYONLUMINEUX_H

#include <direction.h>
#include <Vector3.h>

class Ray
{
    public:

        Vector3 direction;
        Vector3 origin;

        Ray(const Vector3 &direction,  const Vector3 &origin);

};

#endif // RAYONLUMINEUX_H
