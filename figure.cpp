#include "figure.h"
#include "shape.h"
#include "Vector2.h"
#include <iostream>
#include <string>
#include <cmath>

Figure::Figure(){
    shapeAmount = 0;
    maxAmountOfShapes = 4;
    shapearray = new Shape*[maxAmountOfShapes];
    boundingArray = new Vertices[2];
    //Resets size for + operator overload to properly index
    figureVectors.resetSize();
}

Figure::~Figure(){
    if(shapearray){
        delete [] shapearray;
    }
    if(boundingArray){
        delete [] boundingArray;
    }
}

void Figure::addArr(Vector2 v){
    figureVectors + v;
}

void Figure::addShape(Shape *s){
    shapeAmount++;
    if(shapeAmount == maxAmountOfShapes){
        maxAmountOfShapes *= 2;
        Shape **tempShapeArray = new Shape*[maxAmountOfShapes];
        delete [] shapearray;
        shapearray = tempShapeArray;
    }
    int prevIndex = shapeAmount - 1;
    shapearray[prevIndex] = s;
}

void Figure::printBoundingBox(){
    if(shapeAmount == 1){
        std::cout << boundingArray[1].x << " " << boundingArray[0].y;
    }
    else{
        for(int i = 0; i < 2; i++){
            std::cout << boundingArray[i].x << " " << boundingArray[i].y << std::endl;
        }
    }
}

Vertices* Figure::getBoundingBox(){
    tempVector = figureVectors.getArrPointer();
    float minX;
    float minY;
    float maxX;
    float maxY;
    initializeMinMax(minX,minY,maxX,maxY);
    for(int i = 0; i < figureVectors.getSize();i++){
        if(tempVector[i].x < minX){
            minX = tempVector[i].x;
        }
        if(tempVector[i].y < minY){
            minY = tempVector[i].y;
        }
        if(tempVector[i].x > maxX){
            maxX = tempVector[i].x;
        }
        if(tempVector[i].y > maxY){
            maxY = tempVector[i].y;
        }
    }
    //Top left is index 0
    boundingArray[0].x = roundf(minX * 1000) / 1000;
    boundingArray[0].y = roundf(maxY * 1000) / 1000;
    //Bottom right is index 1
    boundingArray[1].x = roundf(maxX * 1000) / 1000;
    boundingArray[1].y = roundf(minY * 1000) / 1000;
    return boundingArray;
}

//Initialises min/max values

void Figure::initializeMinMax(float& miX,float& miY,float& maX,float& maY){
    miX = tempVector[1].x;
    miY = tempVector[1].y;
    maX = tempVector[1].x;
    maY = tempVector[1].y;

    for(int i = 0; i < figureVectors.getSize();i++){
        if(tempVector[i].x < miX){
            miX = tempVector[i].x;
        }
        else if (tempVector[i].x > maX){
            maX = tempVector[i].x;
        }
        else if (tempVector[i].y < miY){
            miY = tempVector[i].y;
        }
        else if (tempVector[i].y > maY){
            maY = tempVector[i].y;
        }
    }
}
