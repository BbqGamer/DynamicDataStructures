#include <iostream>
#include "LinkedList.h"
#include "BST.h"
#include "AVL.h"
#include "Person.h"
#include "includes.h"

#define STARTING 2000
#define ENDING 60000
#define STEP 2000

void experiment(std::vector<TestSubject*> subjects, std::string inputFile="../data/people.txt", std::string outputFile="../output/output.csv", 
                int start=STARTING, int end=ENDING, int step=STEP) {

    std::ofstream f;
    f.open(outputFile);
    f << "structure,operation,n,time" << std::endl;
    f.close();

    for(int n = start; n <= end; n += step) {
        for(auto subject: subjects) {
            subject->setInputFile(inputFile);
            subject->setOutputFile(outputFile);
            subject->test(n);
        }
    }
}

int main() {

    std::vector<TestSubject*> subjects1 = {new LinkedList(), new BST(), new AVL()};
    experiment(subjects1);

    std::vector<TestSubject*> subjects2 = {new BST(), new AVL()};
    experiment(subjects2, "../data/people.txt", "../output/output2.csv", 20000, 1000000, 20000);

    return 0;
}
