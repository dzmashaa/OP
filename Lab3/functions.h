#include <iostream>
#include <string>
#include <iomanip>
#include "Plane.h"
using namespace std;

int enterSizeArray();                               // введення розміру масиву
int correctInputNumberInt(string);                  // перевірка на коректність вводу для значень типу int
float correctInputNumberDouble(string);             // перевірка на коректність вводу для значень типу double
void createArray(Plane*, int );                     // створення масиву
void printArray(Plane *, int);                      // виведення масиву
void findPlaneContainPoint(Plane* arr, int size);   // пошук площин яким належить точка