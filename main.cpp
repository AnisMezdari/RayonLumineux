#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <sphere.h>
#include <rayonlumineux.h>
#include <math.h>
#include <qimage.h>
#include <QtGui>
#include <qlabel.h>
#include <optional>


using namespace std;

 optional<float>  intersection(Sphere sphere , RayonLumineux rayonL );
float carre(float nb);


float produitScalaire(Point a, Point b){
   return  (a.x * b.x ) + (a.y * b.y) + (a.z * b.z);
}

int clamp(int min, int max, int value)
{
    if (value < min) return  min;
    if (value > max) return  max;
    return value;
}

float campMin(int min, float value){
    if(value < min ) return min;
    return value;
}

Point soustraction(Point vecteur1, Point vecteur2){
    return Point(vecteur2.x-vecteur1.x, vecteur2.y-vecteur1.y , vecteur2.z-vecteur1.z);
}

float norme(Point vecteur){
    return sqrt(carre(vecteur.x) + carre(vecteur.y) + carre(vecteur.z) );
}
Point normalisation(Point vecteur){
    return Point(vecteur.x / norme(vecteur),vecteur.y / norme(vecteur), vecteur.z / norme(vecteur) );
}

QImage setImage(QImage image,std::list<Sphere> listSphere, Point lumiere, Point lumiere2){
 QColor c;
    for(int i =0 ; i < 1000; ++i){
         for(int j =0 ; j < 1000; ++j){
            //qInfo() <<  i << "_" <<  j;
            RayonLumineux rl(Point(0,0,1),Point(i,j,0));
             for (std::list<Sphere>::iterator it=listSphere.begin(); it != listSphere.end(); ++it){
                float t = intersection(*it,rl).value_or(0);
                if(t > 0){
                    Point intersectionv(i,j,t);
                    Point vecteurVersLumire = normalisation( soustraction(intersectionv,lumiere ) );

                    Point vercteurNormal = normalisation(soustraction(it->centre ,intersectionv) );
                    Point vecteurVersLumiere2 = normalisation( soustraction(intersectionv,lumiere2 ) );

                    float impactLumineuse = produitScalaire(vecteurVersLumire ,vercteurNormal);
                    float impactLumineuse2 = produitScalaire(vecteurVersLumiere2 ,vercteurNormal);

                    float t1 = intersection(*it,RayonLumineux(vecteurVersLumire,lumiere)).value_or(0);
                    float t2 = intersection(*it, RayonLumineux(vecteurVersLumiere2,lumiere2)).value_or(0);

                    if(t1>0 ){
                        impactLumineuse = 0;

                    }
                    if(t2 > 0){
                        impactLumineuse2 = 0;
                    }

                    //float impactLumineuseSomme  = campMin(0,(impactLumineuse+impactLumineuse2));

                    int calcul = (int) (   (1/(t*t) * ( impactLumineuse * 5000000 ) ));
                    int calcul2 = (int) (   (1/(t*t) * ( impactLumineuse2 * 5000000 ) ));

                    if(calcul < 0){
                        calcul = 0;
                    }
                    if(calcul2 < 0){
                       calcul2 = 0;
                    }
                    int finalCalcul  = calcul + calcul2;

                    finalCalcul =  clamp(0,255,finalCalcul);
                    c.setRgb( finalCalcul ,finalCalcul ,finalCalcul);
                }else{
                    c.setRgb(0,0,0);
                }
                image.setPixelColor(i,j,image.pixelColor(i,j).rgb()+c.rgba());
            }
         }
    }
    return image;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QImage image(1000,1000, QImage::Format_RGB888);
    QLabel myLabel(&w);

    Sphere sphere(100,Point(400,300,200));
    Sphere sphere4(200,Point(250,250,400));
    Sphere sphere1(100,Point(50,100,200));
    Sphere sphere3(100,Point(500,500,200));

    list<Sphere> listSphere;

    listSphere.push_back(sphere);
    listSphere.push_back(sphere1);
    listSphere.push_back(sphere3);
    listSphere.push_back(sphere4);

   image = setImage(image,listSphere, Point(400,0,0),Point(800,800,400));
   myLabel.setPixmap(QPixmap::fromImage(image));
   myLabel.setFixedHeight(1000);
   myLabel.setFixedWidth(1000);

    w.show();
    return a.exec();
}


float carre(float nb){
    return nb * nb;
}

 optional<float>   intersection(Sphere sphere , RayonLumineux rayonL ){
    float b;
    float c;
    float t = 0;
    float t1;

    b = (2 * produitScalaire(rayonL.point,rayonL.direction)) -  (2 * produitScalaire(sphere.centre,rayonL.direction));
    c = produitScalaire(rayonL.point , rayonL.point) + produitScalaire(sphere.centre,sphere.centre) - (2 * produitScalaire(sphere.centre,rayonL.point)) - (sphere.rayon * sphere.rayon);

    float delta = (b*b) - (4*c);

    if(delta >= 0){
        t = (-b + sqrt(delta)) / 2;
        t1 = (-b -  sqrt(delta)) /2;
        float minT = fminf(t,t1);
        if(minT >= 0  ){
            return minT;
        }
        float maxT = fmaxf(t,t1);
        if(maxT >= 0){
            return maxT;
        }
    }
    return {};
}


void genereRayon(){
    RayonLumineux rl(Point(3,3,0),Point(1,4,0));
    Sphere sphere(1,Point(6,2,5));
}





