#include "IntArray.h"
#include <iostream>
#include <iomanip>
using namespace std;

IntArray::IntArray(): TArray(5)
{
    arr = new int[size];
}

void IntArray::fill_array()
{
    for(int i = 0; i < size; i++)
        arr[i] = rand()%101 - 50;
}
void IntArray ::show_array()
{
    for(int i = 0; i < size; i++)
        cout << setw(3) << arr[i] << " ";
    cout << endl;
}

void IntArray :: increase_elements(int num)
{
    for(int i = 0; i < size; i++)
        arr[i] += num;
}
void IntArray ::reduce_elements(int num)
{
    for(int i = 0; i < size; i++)
        arr[i] -= num;
}
double IntArray ::find_arithmetic_mean()
{
    double sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum/size;
}
IntArray :: ~IntArray()
{
    delete[] arr;
}