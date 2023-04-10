#include "functions.h"
Plane::Plane()
{
    A = 1;
    B = 0;
    C = 0;
    D = 0;

}
Plane :: Plane(string s)
{
    cout << setw(10) << s <<endl;
    A = correctInputNumberDouble("Enter A:");
    B = correctInputNumberDouble("Enter B:");
    C = correctInputNumberDouble("Enter C:");
    D = correctInputNumberDouble("Enter D:");

}
Point::Point()
{
    x = correctInputNumberDouble("Enter x:");
    y = correctInputNumberDouble("Enter y:");
    z = correctInputNumberDouble("Enter z:");
}
void Plane::printPlane() const
{
    cout <<  A << "x + " << B << "y + " << C << "z + "
    << D << " = 0" << endl;
}

float Plane::getA() const
{
    return A;
}
float Plane::getB() const
{
    return B;
}
float Plane::getC() const
{
    return C;
}
float Plane::getD() const
{
    return D;
}
float Point :: getX() const
{
    return x;
}
float Point :: getY() const
{
    return y;
}
float Point :: getZ() const
{
    return z;
}
void Point::printCoordinates() const
{
    cout << "(" << x << ";" << y << ";" << z << ")" << endl;
}