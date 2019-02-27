#ifndef POINT_H
#define POINT_H

#include "shape.h"
#include "vector2.h"

class Point : public Shape
{
    public:
        Point(Vertices *sentCoord);
        float area();
        const char* getType();
        float circumference();
        bool isConvex();
        Vertices position();
        Vertices* getArrPointer();
    private:
        Vertices tempVector[1];
};

#endif