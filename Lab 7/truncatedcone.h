#ifndef TRUNCATEDCONE_H
#define TRUNCATEDCONE_H

#include <iostream>
#include <cmath>
#include "exeptions.h"

class TruncatedCone {
private:
    double height;
    double lowerRadius;
    double upperRadius;

public:
    TruncatedCone();
    double volume() const;
    char compare(const TruncatedCone&) const;
    void set_height(double);
    void set_lowerRadius(double);
    void set_upperRadius(double);
    double get_height() const;
    double get_lowerRadius() const;
    double get_upperRadius() const;
};
#endif // TRUNCATEDCONE_H
