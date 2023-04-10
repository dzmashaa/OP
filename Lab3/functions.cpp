#include "functions.h"
#include <cmath>

int correctInputNumberInt(const string line)
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
float correctInputNumberDouble(const string line)
{
    float n;
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
        size = correctInputNumberInt("Enter size of array:");
        if(size <= 0)
        {
            error = true;
            cout << "Size can`t be less than 1" << endl;
        }
    }while(error);
    return size;
}
void createArray(Plane *pl, int size)
{
    for(int i = 0; i < size; i++ )
    {
        string str = "Record #" + to_string(i + 1);
        pl[i] = Plane(str);
        cout << "Your plane:";
        pl[i].printPlane();
    }
    printArray(pl, size);
}
void printArray(Plane *pl, int size)
{
    cout << "\nARRAY OF PLANES" << endl;
    for(int i = 0; i < size; i++ ){
        cout << i +1 << ")";
        pl[i].printPlane();
    }
}

void findPlaneContainPoint(Plane* arr, int size)
{
    cout << "Enter a coordinates of point" << endl;
    Point point;
    bool f = false;
    cout << "This point has coordinates:";
    point.printCoordinates();
    cout << "\nPlanes containing the point:" << endl;
    for (int i = 0; i < size; i++) {
        float result = arr[i].getA() * point.getX() + arr[i].getB() * point.getY() + arr[i].getC() * point.getZ() + arr[i].getD();
        if (fabs(result) < pow(10, -6)) {
            arr[i].printPlane();
            f = true;
        }
    }
    if(!f)
        cout << "no plane contains this point" << endl;
}
