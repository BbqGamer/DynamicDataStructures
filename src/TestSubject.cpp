#include "TestSubject.h"

void TestSubject::readNpeople(int n) {
    //READS FROM INPUT FILE n PEOPLE AND SHUFFLES THEM 
    std::ifstream f;
    int index;
    std::string firstname;
    std::string lastname;
    f.open(inputFile);
    if(f.is_open()) {
        for(int i = 0; i < n; i++) {
            f >> index >> firstname >> lastname;        
            Person p = Person(index, firstname, lastname);
            people.push_back(p);
        }
    }
    std::random_shuffle(people.begin(), people.end());
}

void TestSubject::setInputFile(std::string file) {
    inputFile = file;
}