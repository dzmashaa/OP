#include <iostream>
#ifndef LAB4_SEGMENT_H
#define LAB4_SEGMENT_H
class Segment;

class Point {
    float x, y;
    friend class Segment;
public:
    Point();                    // конструктор за замовчуванням
    Point(std::string);         // конструктор з параметрами
    void printPoint() const;    // метод виведення об'єкта
};


class Segment {
    Point  start, end;

public:
    Segment();// конструктор за замовчуванням
    Segment(std::string, std::string); // конструктор з параметрами
    Segment(float, float, float, float); // конструктор з параметрами
    Segment(Segment&);// конструктор копіювання
    void printSegmentCoordinate(std::string) const; // метод виведення об'єкта
    Segment operator+(Segment) const; // перевантажений оператор бінарний "+"
    Segment operator++(int); // перевантажений оператор постфіксного інкременту
    std::string pointBelongsSegment(Point&) const; //метод перевірки, чи належить точка відрізку
};


#endif //LAB4_SEGMENT_H
