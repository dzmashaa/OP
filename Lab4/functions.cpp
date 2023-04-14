#include "functions.h"


float correctInputNumberFloat(const string line)
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

