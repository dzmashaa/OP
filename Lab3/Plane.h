#include <string>
#ifndef UNTITLED_PLANE_H
#define UNTITLED_PLANE_H
class Point{
    float x, y, z;
public:
    Point();
    float getX() const;
    float getY() const;
    float getZ() const;
    void printCoordinates() const;

};

class Plane {
float A, B, C, D;
public:
    Plane();
    Plane(std::string);
    void printPlane() const;
    float getA() const;
    float getB() const;
    float getC() const;
    float getD() const;

};


#endif //UNTITLED_PLANE_H
