#include "scene.h"
#include "intersect.h"
#include <limits>
#include <omp.h>
#include <iostream>

Scene::Scene()
{

}


void Scene::add(const Light &light){
    this->listLight.push_back(light);
}
void Scene::add(const Sphere &sphere){
    this->listSphere.push_back(sphere);
}
bool Scene::intersect(const Ray &ray , float &distance) const {
    float min = std::numeric_limits<float>::max();
    for(const Sphere &mySphere : this->listSphere){
        float temp;
        if(intersectSphere(mySphere, ray, temp)){
            if(temp < min){
                min = temp;
            }
        }
    }

    //std::cout << "Ray" << ray.origin << " Distance = " << min << std::endl;
    if(min >= std::numeric_limits<float>::max()){
        return false;
    }
    distance = min;
    return true;

}

void Scene::render(QImage &img) const {

    //#pragma omp parallel for
    for(int i = 0; i < img.width() ; i++){
        for(int j = 0 ; j < img.height() ; j++){
            float x = 0.5f + i - (img.width() / 2);
            float y = 0.5f + j - (img.height() / 2);
            if (i == 200 && j == 200) std::cout << Vector3(x,y,0) << std::endl;

             Ray ray = Ray(Vector3(0, 0, 1), Vector3(x,y,0));

             QColor color(0, 0, 0);

             float distance;
             if (this->intersect(ray, distance))
             {
                 color.setRgbF(1.0, 1.0, 1.0);
             }

             img.setPixelColor(i, j, color);
        }
    }
}

