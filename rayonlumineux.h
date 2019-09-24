#ifndef RAYONLUMINEUX_H
#define RAYONLUMINEUX_H

#include <direction.h>
#include <point.h>

class RayonLumineux
{
    public:

        Point direction;
        Point point;

        RayonLumineux(Point direction ,  Point point);

};

#endif // RAYONLUMINEUX_H
