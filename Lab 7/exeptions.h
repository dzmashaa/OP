#ifndef EXEPTIONS_H
#define EXEPTIONS_H

#include <iostream>
#include <exception>
class incorrect_height : public std::exception{
public:
    const char* what() const throw();
};

class incorrect_radiuses : public std::exception{
public:
    const char* what() const throw();
};

void check_radiuses(double, double);
void check_height(double);


#endif // EXEPTIONS_H
