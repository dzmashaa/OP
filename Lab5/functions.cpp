#include "functions.h"

void fill_arrays(IntArray* iarr, DoubleArray* darr, int num)
{
    for(int i = 0; i < num; i++)
        iarr[i].fill_array();

    for(int i = 0; i < num; i++)
        darr[i].fill_array();
}
void print_arrays(IntArray* iarr, DoubleArray* darr, int num)
{
    cout << "Int arrays:" << endl;
    for(int i = 0; i < num; i++) {
        cout << i + 1 << ')';
        iarr[i].show_array();
    }
    cout << "Double arrays:" << endl;
    for(int i = 0; i < num; i++) {
        cout << i + 1 << ')';
        darr[i].show_array();
    }
}
void change_arrays(IntArray* iarr, DoubleArray* darr, int size)
{
    int number = correctInputNumberInt("Enter number to change arrays:");
    for(int i = 0; i < size; i++)
        iarr[i].increase_elements(number);
    for(int i = 0; i < size; i++)
        darr[i].reduce_elements(number);
}

void find_max_arithmetic_mean(IntArray* iarr, DoubleArray* darr, int size)
{
    double max_int = iarr[0].find_arithmetic_mean();
    int index_int = 0;
    for(int i = 1; i < size; i++)
    {
        double temp = iarr[i].find_arithmetic_mean();
        if(temp > max_int) {
            max_int = temp;
            index_int = i;
        }
    }
    double max_double = darr[0].find_arithmetic_mean();
    int index_double = 0;
    for(int i = 1; i < size; i++)
    {
        double temp = darr[i].find_arithmetic_mean();
        if(temp > max_int) {
            max_double = temp;
            index_double = i;
        }
    }
    cout << "\nArray with the largest average value:\n";
    if(max_int > max_double) {
        iarr[index_int].show_array();
        cout << "(value = " << max_int << ')'<< endl;
    }
    else
    {
        darr[index_double].show_array();
        cout << "(value = " << max_double << ')'<< endl;
    }
}
int correctInputNumberInt(string line)
{
    int n;
    char ch;
    bool check;
    do
    {
        check = true;
        cout << line;
        cin >> n;
        cin.get(ch);
        if(cin.fail() || (ch != '\n'))
        {
            check = false;
            cout << "Error: incorrect input\n";
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while(!check);
    return n;
}
int enterSizeArray()
{
    int size;
    bool error;
    do {
        error = false;
        size = correctInputNumberInt("Enter the number of array:");
        if(size <= 0)
        {
            error = true;
            cout << "Size can`t be less than 1" << endl;
        }
    }while(error);
    return size;
}