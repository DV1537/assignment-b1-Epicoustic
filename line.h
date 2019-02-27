#ifndef LINE_H
#define LINE_H

#include "vector2.h"
#include "shape.h"

class Line : public Shape
{
    public:
        Line(Vertices *sentCoord,const int size);
        const char* getType();
        float area();
        float circumference();
        bool isConvex();
        Vertices position();
        Vertices* getArrPointer();
    private:
        Vertices tempVector[2];
};

#endif