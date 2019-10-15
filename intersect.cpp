#include "intersect.h"
#include <math.h>
#include <iostream>

bool intersectSphere(const Sphere &sphere, const Ray &ray, float &distance){
    float b = 2 * (ray.origin.dotProduct(ray.direction) - sphere.center.dotProduct(ray.direction));
    float c = ray.origin.dotProduct(ray.origin) + sphere.center.dotProduct(sphere.center) - 2 * sphere.center.dotProduct(ray.origin) - sphere.radius * sphere.radius;

    float discriminant = (b * b) - (4 * c);
    std::cout << discriminant << std::endl;

    if (discriminant < 0)
      return false;

    //Find distance solutions (they might be negative !)
    float sqrtDiscriminant = std::sqrt(discriminant);
    float t = (-b - sqrtDiscriminant) / 2.f;
    if (t < 0)
      t = (-b + sqrtDiscriminant) / 2.f;

    std::cout << t << std::endl;

    if (t < 0)
      return false;

    //At this point we're sure we hit something at the distance of t > 0. Update the output references
    distance = t;
    return true;
}
