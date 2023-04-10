#include "functions.h"

struct time{
    int hour, minute;
};
struct timetable
{
    int number;
    char direction[100];
    struct time departure_time;
    struct time arrival_time;
};
int input_number(string line)
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
int input_hour(string line)
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
        if(cin.fail() || (ch != '\n') || n < 0 || n > 23)
        {
            check = false;
            cout << "Error: incorrect input " << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while(!check);
    return n;
}
int input_minute( string line )
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
        if(cin.fail() || (ch != '\n') || n < 0 || n > 59)
        {
            check = false;
            cout << "Error: incorrect input" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while(!check);
    return n;
}
void dataInput(ofstream &f)
{
    timetable table {};
    short choice = 1;
    while(choice == 1){
        table.number = input_number("Train number:");
        cout << "Direction:";
        cin.getline(table.direction, 100);
        table.departure_time.hour = input_hour("Departure time(hours):");
        table.departure_time.minute = input_minute("Departure time(minutes):");
        table.arrival_time.hour = input_hour("Arrival time(hours):");
        table.arrival_time.minute = input_minute("Arrival time(minutes):");
        f.write((char *)&table, sizeof(timetable));
        printRecord(table);
        cout << "Add new record( enter 1 if yes)"<< endl;
        cin >> choice;
    }

}
void createFile(string name)
{
    ofstream file(name, ios::binary);
    if(file.is_open())
        dataInput(file);
    else
        cout << "Error: cannot open file" << endl;
    file.close();
}
void printTitle()
{
   cout << left << setw(15) << "Train number";
   cout << left << setw(15) << "Direction";
   cout << left << setw(20) << "Departure time";
   cout << left << setw(20) << "Arrival time";
   cout << endl;
}
void printRoute(timetable &t)
{
    string d_time = to_string(t.departure_time.hour) + ":" + to_string(t.departure_time.minute);
    string a_time = to_string(t.arrival_time.hour) + ":" + to_string(t.arrival_time.minute);
    cout << left << setw(15) << t.number;
    cout << left << setw(15) << t.direction;
    cout << left << setw(20) << d_time;
    cout << left << setw(20) << a_time;
    cout << endl;
}
void printFile(string name)
{
    ifstream file(name, ios::binary);
    timetable table {};
    if(file.is_open()) {
        printTitle();
        while (file.read((char *) &table, sizeof(timetable)))
            printRoute(table);
    }
    file.close();
}
void printRecord(timetable &p )
{
    cout << setw(20) << "-------------------" << endl;
    cout << "Train number: " << p.number << endl;
    cout << "Direction: " << p.direction << endl;
    cout << "Departure time: "<< p.departure_time.hour << ":"<< p.departure_time.minute << endl;
    cout << "Arrival time: " << p.arrival_time.hour << ":" << p.arrival_time.minute << endl;
    cout << setw(20) << "-------------------" << endl;
}
void createNewFile(string in_name, string out_name)
{
    ofstream fout(out_name, ios::binary);
    ifstream fin(in_name, ios::binary);
    timetable table {};
    while(fin.read((char *) &table, sizeof(timetable)))
        if(table.departure_time.hour < 10 || table.departure_time.hour >= 18)
            fout.write((char *) &table, sizeof(timetable));
    fin.close();
    fout.close();
}
void addData(string name)
{
    ofstream file(name, ios::binary | ios::app);
    if(file.is_open())
        dataInput(file);
    else
        cout << "Error: cannot open file" << endl;
    file.close();
}

