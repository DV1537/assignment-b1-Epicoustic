#include "vector2.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Vector2::Vector2(){
    arraysize = 5;
    maxSize = arraysize;
    vectorArray = new Vertices[arraysize];
    combinedSize = 0;
}

Vector2::Vector2(const Vector2& v){
    maxSize = v.maxSize;
    arraysize = v.arraysize;
    combinedSize = arraysize;
    vectorArray = new Vertices[maxSize];
    for (int i = 0; i < arraysize; i++){
        vectorArray[i] = v.vectorArray[i];
    }
}

Vector2::~Vector2(){
    if (vectorArray) {
        delete[] vectorArray;
        vectorArray = nullptr;
    }
}

Vertices* Vector2::getArrPointer(){
    return vectorArray;
}

void Vector2::expandVectorArray(){
    int oldSize = maxSize;
    maxSize *= 2;
    Vertices *tempArray = new Vertices[maxSize];
    memcpy(tempArray, vectorArray, sizeof(Vertices) * oldSize);
    delete [] vectorArray;
    vectorArray = tempArray;
}

Vector2 Vector2::operator+(const Vector2 &v) {
    combinedSize = this->arraysize + v.arraysize;
    int firstVerticeLength = this->arraysize;
    while(combinedSize >= maxSize){
        this->expandVectorArray();
    }

    int j = 0;

    for (int i = firstVerticeLength; i < combinedSize; i++) {
        this->vectorArray[i] = v.vectorArray[j];
        j++;
    }
    this->arraysize = combinedSize;
    return *this;
}


void Vector2::resetSize(){
    this->arraysize = 0;
}

Vector2& Vector2::operator=(const Vector2 &v){
    if (!(this == &v)) {
        delete[] vectorArray;
        vectorArray = nullptr;
        maxSize = v.maxSize;
        arraysize = v.arraysize;
        combinedSize = arraysize;
        vectorArray = new Vertices[v.combinedSize];
        for (int i = 0; i < v.combinedSize; i++) {
            this->vectorArray[i] = v.vectorArray[i];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out,const Vector2& v){
	for (int i = 0; i < v.arraysize; i++){
		out << v.vectorArray[i].x << " " << v.vectorArray[i].y << std::endl;
	}
	return out;
}

int Vector2::getSize(){
    return arraysize;
}

//Reads values and checks validity

bool Vector2::readVertices(std::stringstream &ss) {
    int iteration = 0;
    bool readValid = true;
    while (!(ss.fail() || ss.eof())) {;
        ss >> this->vectorArray[iteration].x >> this->vectorArray[iteration].y;
        if (this->arraysize >= this->maxSize) {
            //expands maxsize
            this->expandVectorArray();
        }
        iteration++;
        
    }
    if(ss.fail()){
        readValid = false;
    }
    this->arraysize = iteration;
    return readValid;
}