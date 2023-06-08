#include "truncatedcone.h"

TruncatedCone::TruncatedCone()
{
    height = 0;
    lowerRadius = 0;
    upperRadius = 0;
}



double TruncatedCone :: volume() const
{
    double volume = (1.0 / 3.0) * M_PI * height * (pow(lowerRadius, 2) + lowerRadius * upperRadius + pow(upperRadius, 2));
    return volume;
}

void TruncatedCone :: set_height(double h)
{
    height = h;
}

void TruncatedCone :: set_lowerRadius(double lr)
{
    lowerRadius = lr;
}
void TruncatedCone :: set_upperRadius(double ur)
{
    upperRadius = ur;
}

char TruncatedCone :: compare(const TruncatedCone& other) const
{
    double volume1 = volume();
    double volume2 = other.volume();
    if (std::abs(volume1 - volume2) < 0.0001) {
        return '=';
    } else if (volume1 < volume2) {
        return '<';
    } else {
        return '>';
    }
}

double TruncatedCone :: get_height() const
{
    return height;
}
double TruncatedCone :: get_lowerRadius() const
{
    return lowerRadius;
}
double TruncatedCone :: get_upperRadius() const
{
    return upperRadius;
}
