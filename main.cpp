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



Point soustraction(Point vecteur1, Point vecteur2){
    return Point(vecteur2.x-vecteur1.x, vecteur2.y-vecteur1.y , vecteur2.z-vecteur1.z);
}

float norme(Point vecteur){
    return sqrt(carre(vecteur.x) + carre(vecteur.y) + carre(vecteur.z) );
}
Point normalisation(Point vecteur){
    return Point(vecteur.x / norme(vecteur),vecteur.y / norme(vecteur), vecteur.z / norme(vecteur) );
}

QImage setImage(QImage image,std::list<Sphere> listSphere, Point lumiere){
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

                    int calcul = (int) (   (1/(t*t) * (produitScalaire(vecteurVersLumire ,vercteurNormal) * 10000000 ) ));

//                    qInfo() << produitScalaire(vecteurVersLumire ,vercteurNormal) << " produitScalie";
//                    qInfo() << 1/(t*t) << " 1/t*t";
//                    qInfo() << calcul;
                    calcul = clamp(1,255,calcul);
                    c.setRgb( calcul,calcul,calcul);

                    //qInfo() << calcul;
                    //c.setRgb( 128,0,128);
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

    Sphere sphere(200,Point(500,150,400));
    //Sphere sphere4(200,Point(250,250,400));
    Sphere sphere1(100,Point(50,100,200));
    Sphere sphere3(100,Point(500,500,200));

    list<Sphere> listSphere;

    listSphere.push_back(sphere);
    listSphere.push_back(sphere1);
    listSphere.push_back(sphere3);
    //listSphere.push_back(sphere4);

   image = setImage(image,listSphere, Point(250,450,10));
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




