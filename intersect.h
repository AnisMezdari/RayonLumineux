#ifndef INTERSECT_H
#define INTERSECT_H

#include "sphere.h"
#include "ray.h"


bool intersectSphere(const Sphere &sphere, const Ray &ray, float &distance);

#endif // INTERSECT_H
