#ifndef LUMIERE_H
#define LUMIERE_H

#include <Vector3.h>
#include <qimage.h>

class Light
{
public:
    Vector3 position;
    QColor color;
    Light(Vector3 position, QColor color);

};

#endif // LUMIERE_H
