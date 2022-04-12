#ifndef PERSON_H
#define PERSON_H

#include "includes.h"

class Person {
    int index;
    std::string firstname;
    std::string lastname;

public:
    Person() {};
    Person(int _index, std::string _firstname, std::string _lastname): index(_index), firstname(_firstname), lastname(_lastname) {};

    int getIndex();
    std::string getFirstname();
    std::string getLastname();

    int operator==(Person& other) {
        return (index == other.index && firstname == other.firstname && lastname == other.lastname);
    }
};

#endif