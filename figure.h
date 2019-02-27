#ifndef FIGURE_H
#define FIGURE_H

#include "Figure.h"
#include "shape.h"
#include "vector2.h"

class Figure : public Shape {
    public:
        void addShape(Shape *s);
        Figure();
        ~Figure();
        void addArr(Vector2 v);
        Vertices* getBoundingBox();
        void initializeMinMax(float& miX,float& miY,float& maX,float& maY);
        void printBoundingBox();
    private:
        int maxAmountOfShapes;
        Vector2 figureVectors;
        Vertices* boundingArray;
        Vertices* tempVector;
        Shape **shapearray;
        int shapeAmount;
};

#endif