#ifndef PERSON_H
#define PERSON_H

#include "includes.h"

class Person {
    int index;
    std::string firstname;
    std::string lastname;

public:
    int getIndex();
    std::string getFirstname();
    std::string getLastname();
};

#endif