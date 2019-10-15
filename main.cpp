#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
#include <sphere.h>
#include <ray.h>
#include <math.h>
#include <qimage.h>
#include <QtGui>
#include <qlabel.h>
#include <optional>
#include <light.h>
#include "scene.h"

using namespace std;

int clamp(int min, int max, int value)
{
    if (value <= min) return  min;
    if (value >= max) return  max;
    return value;
}

/*
QImage setImage(QImage image,std::list<Sphere> listSphere, Vector3 lumiere , Vector3 lumiere2 ){
 QColor c;float mint= 1000000000.f;
    for(int i =0 ; i < 1000; ++i){
         for(int j =0 ; j < 1000; ++j){
             c.setRgb(0,0,0);
            //qInfo() <<  i << "_" <<  j;
            Ray rl(Vector3(0,0,1),Vector3(i,j,0));

             mint= 1000000000.f;
             for (std::list<Sphere>::iterator it=listSphere.begin(); it != listSphere.end(); ++it){

                float t = intersection(*it,rl).value_or(0);

                if(t > 0 && t<mint){
                    mint = t;
                    Vector3 intersectionv(i,j,t);
                    Vector3 vecteurVersLumire = normalisation( soustraction(intersectionv,lumiere ) );

                    Vector3 vercteurNormal = normalisation(soustraction(it->center ,intersectionv) );
                    Vector3 vecteurVersLumiere2 = normalisation( soustraction(intersectionv,lumiere2 ));

                    float impactLumineuse = produitScalaire(vecteurVersLumire ,vercteurNormal);
                    float impactLumineuse2 = produitScalaire(vecteurVersLumiere2 ,vercteurNormal);

                    int calcul = (int) ( (1/(t*t) * ( impactLumineuse * 5000000 ) ));
                    int calcul2 = (int) ( (1/(t*t) * ( impactLumineuse2 * 5000000 ) ));

                    if(calcul < 0){
                        calcul = 0;
                    }
                    if(calcul2 < 0){
                       calcul2 = 0;
                    }
                    if(calcul > 0 && calcul2 >0){
                        cout << calcul << " + " << calcul2 << " = " << (calcul + calcul2) <<"\n";
                    }
                    int finalCalcul  = (calcul + calcul2);
                    //cout << calcul << "+" << calcul2 << " = " << finalCalcul << "\n";
                    //int finalCalcul  = calcul;


                    finalCalcul =  clamp(0,255,finalCalcul);
                    c.setRgb( finalCalcul ,finalCalcul ,finalCalcul);
                }
                image.setPixelColor(i,j,c.rgba());
            } // fin de for
         }
    }
    return image;
}
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QImage image(400,400, QImage::Format_RGB32);
    QLabel myLabel(&w);

    Scene scene;
    scene.add(Sphere(100, Vector3(0, 0, 200)));
    scene.add(Sphere(70, Vector3(-150, -150, 400)));
    scene.add(Sphere(30, Vector3(100, 50, 100)));

    scene.render(image);

    myLabel.setPixmap(QPixmap::fromImage(image));
    myLabel.setFixedHeight(image.width());
    myLabel.setFixedWidth(image.height());


    w.resize(image.width(), image.height());
    w.show();
    return a.exec();
}

/*
float carre(float nb){
    return nb * nb;
}

 optional<float>   intersection(Sphere sphere , Ray rayonL ){
    float b;
    float c;
    float t = 0;
    float t1;

    b = (2 * produitScalaire(rayonL.origin,rayonL.direction)) -  (2 * produitScalaire(sphere.center,rayonL.direction));
    c = produitScalaire(rayonL.origin , rayonL.origin) + produitScalaire(sphere.center,sphere.center) - (2 * produitScalaire(sphere.center,rayonL.origin)) - (sphere.radius * sphere.radius);

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
    Ray rl(Vector3(3,3,0),Vector3(1,4,0));
    Sphere sphere(1,Vector3(6,2,5));
}
*/
