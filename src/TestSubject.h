#ifndef TESTSUBJECT_H
#define TESTSUBJECT_H

#include "includes.h"
#include "Person.h"

class TestSubject {
public:
    virtual void insert(Person p) = 0;
    virtual Person search(int index) = 0;
    virtual void remove(int index) = 0;


};

#endif