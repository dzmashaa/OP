#include "functions.h"

int main(int argc, char* argv[])
{
    char mode[] = "-mode";
    char mode1[] = "FilePointer";
    char mode2[] = "FileStream";

    if (argc != 3 || strcmp(argv[1], mode)!=0)
    {
        cout << "Launch the program with particular mode!\n" <<
             ".exe -mode FilePointer/FileStream\n";
    }
    else if (!strcmp(argv[2], mode1))
    {
        mainPointer();
    }
    else if(!strcmp(argv[2], mode2))
    {
        mainSteam();
    }
    else
    {
        cout << "The only modes are FilePointer/FileStream";
    }
    system("pause");
    return 0;
}
