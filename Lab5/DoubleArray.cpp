#include "DoubleArray.h"
#include <iostream>
#include <iomanip>
using namespace std;

DoubleArray::DoubleArray(): TArray(5)
{
    arr = new double[size];
}

void DoubleArray::fill_array()
{
    for(int i = 0; i < size; i++)
        arr[i] = (rand()/(double)RAND_MAX)*100 - 50;
}
void DoubleArray ::show_array()
{
    for(int i = 0; i < size; i++)
        cout << setw(6) << setprecision(2) << fixed << arr[i] << " ";
    cout << endl;
}

void DoubleArray :: increase_elements(int num)
{
    for(int i = 0; i < size; i++)
        arr[i] += num;
}
void DoubleArray ::reduce_elements(int num)
{
    for(int i = 0; i < size; i++)
        arr[i] -= num;
}
double DoubleArray ::find_arithmetic_mean()
{
    double sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum/size;
}
DoubleArray :: ~DoubleArray()
{
    delete[] arr;
}