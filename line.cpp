#include "line.h"
#include <iostream>
#include <cmath>

Line::Line(Vertices *sentCoord,const int size){
    for(int i = 0; i < size; i++){
        tempVector[i].x = sentCoord[i].x;
        tempVector[i].y = sentCoord[i].y;
    }
}

const char* Line::getType(){
    return "Line";
}

float Line::area(){
    return -1;
}


float Line::circumference(){
    float circum = sqrt(pow(tempVector[0].x - tempVector[1].x, 2) + pow(tempVector[0].y - tempVector[1].y, 2)); 
    return circum;
}

bool Line::isConvex(){
    return false;
}

Vertices Line::position(){
    Vertices centroid;
    float centerX;
    float centerY;

    for(int i= 0; i < 2;i++){
        centerX += tempVector[i].x;
        centerY += tempVector[i].y;
    }
    centroid.x = centerX/2;
    centroid.y = centerY/2;
    return centroid;
}

Vertices* Line::getArrPointer(){
    return tempVector;
}