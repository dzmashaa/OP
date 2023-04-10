#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct time;
struct timetable;

void createFile(string);            // створення файлу з розкладом
void createNewFile(string, string); // створення нового файлу з зимовим розкладом
void printRecord(timetable&);       // вивід запису
void addData(string);               // додати дані в вхідний файл
void dataInput(ofstream&);          // ввід даних
int input_minute(string);           // ввід хвилин
int input_hour(string);             // ввід годин
int input_number(string line);      // ввід номеру потягу
void printTitle();                  // вивід заголовка
void printRoute(timetable&);        // вивід маршруту
void printFile(string);             // вивід файлу