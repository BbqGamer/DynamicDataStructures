#ifndef TESTSUBJECT_H
#define TESTSUBJECT_H

#include "includes.h"
#include "Person.h"

class TestSubject {
    std::vector<Person> people;
    std::string inputFile = "./data/people.txt";
    std::string outputFile = "./data/output.csv";

public:
    virtual void insert(Person p) = 0;
    virtual Person search(int index) = 0;
    virtual void remove(int index) = 0;
    virtual std::string getStructureName() = 0;

    void readNpeople(int n);
    double getAverageInsertTime();
    double getAverageSearchTime();
    double getAverageRemoveTime();
    void test(int n);

    void setInputFile(std::string file);
    void setOutputFile(std::string file);
};

#endif