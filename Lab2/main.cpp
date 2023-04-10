#include "functions.h"

int main() {
    string first_file = "timetable.bin";
    string second_file = "winter_timetable.bin";
    createFile(first_file);
    cout << "TIMETABLE:"<< endl;
    printFile(first_file);
    createNewFile( first_file,  second_file);
    cout << "WINTER TIMETABLE:"<< endl;
    printFile(second_file);

    short choice;
    cout << "\nIf you want to add data, press 1\n";
    cin >> choice;
    while(choice == 1){
        addData(first_file);
        cout << "TIMETABLE:" << endl;
        printFile(first_file);
        createNewFile(first_file, second_file);
        cout << "WINTER TIMETABLE:" << endl;
        printFile(second_file);
        cout << "\nIf you want to add data, press 1\n";
        cin >> choice;
    }
    return 0;
}
