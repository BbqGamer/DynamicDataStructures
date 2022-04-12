#ifndef PERSON_H
#define PERSON_H

#include "includes.h"

class Person {
    int index;
    std::string firstname;
    std::string lastname;

public:
    Person(): index(0), firstname(""), lastname("") {};
    Person(int _index, std::string _firstname, std::string _lastname): index(_index), firstname(_firstname), lastname(_lastname) {};

    int getIndex() const;
    std::string getFirstname() const;
    std::string getLastname() const;

    bool operator==(const Person other) const {
        return (index == other.index && firstname == other.firstname && lastname == other.lastname);
    }
};

#endif