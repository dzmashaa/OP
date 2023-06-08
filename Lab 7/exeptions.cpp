#include "exeptions.h"

void check_height(double height)
{
    if(height <= 0)
        throw incorrect_height();
}

const char* incorrect_height::what() const throw(){
    return "Некоректна висота конуса.\n Пам'ятайте, що висота має бути більшою за 0";
}

const char* incorrect_radiuses::what() const throw(){
    return "Радіуси введені некоректно.\n Пам'ятайте, що радіус нижньої основи не можу бути меншим за радіус верхньої основи";
}

void check_radiuses(double r1, double r2)
{
    if(r1 < r2)
        throw incorrect_radiuses();
}
