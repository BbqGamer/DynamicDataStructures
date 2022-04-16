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

void TestSubject::setOutputFile(std::string file) {
    outputFile = file;
}

void TestSubject::test(int n) {
    //TESTS THE INSERT, SEARCH AND REMOVE FUNCTIONS
    readNpeople(n);
    std::ofstream f;
    f.open(outputFile, std::ios_base::app);
    if(f.is_open()) {
        f << this->getStructureName() << ",insert," << n << "," << getAverageInsertTime() << std::endl;
        f << this->getStructureName() << ",search," << n << "," << getAverageSearchTime() << std::endl;
        f << this->getStructureName() << ",remove," << n << "," << getAverageRemoveTime() << std::endl;
    } else {
        std::cout << "ERROR OPENING FILE" << std::endl;
    }
    f.close();
}

double TestSubject::getAverageInsertTime() {
    double insertTime = 0;
    clock_t start, end;
    double cpu_time_used;
    for(auto person : people) {
        start = clock();

        this->insert(person);

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        insertTime += cpu_time_used;
    }
    std::random_shuffle(people.begin(), people.end());

    return insertTime / people.size();
}

double TestSubject::getAverageSearchTime() {
    double searchTime = 0;
    clock_t start, end;
    double cpu_time_used;
    for(auto person : people) {
        start = clock();

        this->search(person.getIndex());

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        searchTime += cpu_time_used;
    }
    std::random_shuffle(people.begin(), people.end());

    return searchTime / people.size();
}

double TestSubject::getAverageRemoveTime() {
    double removeTime = 0;
    clock_t start, end;
    double cpu_time_used;
    for(auto person : people) {
        start = clock();

        this->remove(person.getIndex());

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        removeTime += cpu_time_used;
    }
    removeTime = removeTime / people.size();
    people = std::vector<Person>();
    return removeTime;
}