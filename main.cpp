#include "vector2.h"
#include "shape.h"
#include "line.h"
#include "point.h"
#include "triangle.h"
#include "polygon.h"
#include "figure.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>


float roundedNumber(float n);

int main(int argc, const char *argv[]){
	std::ifstream myReadFile(argv[1]);
	std::string line = "";
	int lineIndex = 0;
	Vector2 coords;
	Figure figures;
	while (!(myReadFile.eof())){
		//reads line by line
		while (getline(myReadFile,line)){
			std::stringstream ss(line);
			if(!(coords.readVertices(ss))){
				std::cout << "Invalid input!";
				return 1;
			}
			Vertices *arrPtr;
			arrPtr = coords.getArrPointer();
			int verticeAmount = coords.getSize();
			Shape* shape;

			if(verticeAmount == 1){
				Point pointObj(arrPtr);
				shape = &pointObj;
			}

			if(verticeAmount == 2){
				Line lineObj(arrPtr,verticeAmount);
				shape = &lineObj;
			}

			if(verticeAmount == 3){
				Triangle triObj(arrPtr,verticeAmount);
				shape= &triObj;
			}

			if(verticeAmount >= 4){
				Polygon polyObj(arrPtr,verticeAmount);
				shape = &polyObj;
			}
			//Saves shape into a "shapearray"
			figures.addShape(shape);
			//Adds coords to figures own "vectorarray"
			figures.addArr(coords);
		}
	}
	figures.getBoundingBox();
	figures.printBoundingBox();
	myReadFile.close();
}

float roundedNumber(float n){
		float roundedNumber = roundf(n * 1000) / 1000;
		return roundedNumber;
}