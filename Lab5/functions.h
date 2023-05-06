#include "IntArray.h"
#include "DoubleArray.h"
#include <ctime>
#include <iostream>
using namespace std;

void fill_arrays(IntArray*, DoubleArray*, int);
void print_arrays(IntArray* iarr, DoubleArray* darr, int num);
int correctInputNumberInt(string);
void change_arrays(IntArray* iarr, DoubleArray* darr, int size);
int enterSizeArray();
void find_max_arithmetic_mean(IntArray* iarr, DoubleArray* darr, int size);