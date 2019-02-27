#include "point.h"
#include <iostream>

Point::Point(Vertices *sentCoord)
{
	tempVector[0].x = sentCoord[0].x;
	tempVector[0].y = sentCoord[0].y;
}

const char* Point::getType(){
	return "Point";
}

float Point::area(){
	return -1;
}

float Point::circumference(){
	return 0;
}

Vertices Point::position(){
	Vertices centroid;
	centroid.x = tempVector[0].x;
	centroid.y = tempVector[0].y;
	return centroid;
}

bool Point::isConvex(){
	return false;
}

Vertices* Point::getArrPointer(){
    return tempVector;
}