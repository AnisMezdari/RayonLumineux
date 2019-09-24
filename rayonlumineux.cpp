#include "rayonlumineux.h"
#include "point.h"

RayonLumineux::RayonLumineux(Point direction , Point point) :  direction(0,0,0) , point(0,0,0)
{
    RayonLumineux::direction = direction;
    RayonLumineux::point = point;
}

