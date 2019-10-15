#ifndef SCENE_H
#define SCENE_H

#include <list>
#include "sphere.h"
#include "light.h"
#include  "ray.h"
class Scene
{
public:
    Scene();
    void add(const Light &light);
    void add(const Sphere &sphere);
    bool intersect(const Ray &r , float &distance) const;
    void render(QImage &img) const;
private :
    std::list<Sphere> listSphere;
    std::list<Light> listLight;
};

#endif // SCENE_H
