#include "Segment.h"
#include "functions.h"
Point::Point(): x(0), y(0)
{}
Point::Point(const string s) {
    cout << s << endl;
    x = correctInputNumberFloat("Enter x:");
    y = correctInputNumberFloat("Enter y:");
}

void Point::printPoint() const
{
    cout << "Your point is (" << x << ";" << y << ")" << endl;
}
Segment ::Segment(): start(), end()
{}
Segment::Segment(Segment& other): start(other.start), end(other.end)
{}

Segment ::Segment(float x1 , float y1 , float x2 , float y2)
{
    start.x = x1;
    start.y = y1;
    end.x = x2;
    end.y = y2;
}
Segment::Segment(const string s1, const string s2)
{
    size_t n = s1.find(';');
    start.x = stof(s1.substr(0, n));
    start.y = stof(s1.substr(n + 1, string::npos));
    n = s2.find(';');
    end.x = stof(s2.substr(0, n));
    end.y = stof(s2.substr(n + 1, string::npos));
}
void Segment::printSegmentCoordinate(string s) const
{
    cout << s << endl;
    cout << "start coordinate (" << start.x << ";" << start.y << ")\n" <<
    "end coordinate (" << end.x << ";" << end.y << ")" << endl;
    cout << setfill('-') << setw(20) << ""<< endl;
}
Segment Segment ::operator+(const Segment obj) const
{
    Segment sum;
    sum.start.x = start.x + obj.start.x;
    sum.start.y = start.y + obj.start.y;
    sum.end.x = end.x + obj.end.x;
    sum.end.y = end.y + obj.end.y;
    return sum;
}
Segment Segment ::operator++(int)
{
   Segment temp = *this;
    ++end.x;
    ++end.y;
    return temp;
}
string Segment::pointBelongsSegment(Point &point) const
{
    float a = (end.y - start.y)/(end.x - start.x);
    float b = start.y - a * start.x;
    bool on_line = fabs(point.y - (a*point.x + b)) < pow(10, -6);
    if(on_line && (start.x <= point.x && point.x <= end.x)
    && (start.y <= point.y && point.y <= end.y))
        return "This point belongs V3 segment";
    return "This point do NOT belong V3 segment";
}