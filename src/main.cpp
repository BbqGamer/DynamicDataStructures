#include <iostream>
#include "LinkedList.h"
#include "BST.h"
#include "AVL.h"
#include "Person.h"
#include "includes.h"

#define STARTING 1000
#define ENDING 100000
#define STEP 10000

int main() {

    std::vector<TestSubject*> subjects = {new AVL()};
    std::ofstream f;
    f.open("../output/output2.csv");
    f << "structure,n,insert,search,remove" << std::endl;
    f.close();

    for(int n = STARTING; n <= ENDING; n += STEP) {
        for(auto subject: subjects) {
            subject->setInputFile("../data/people.txt");
            subject->setOutputFile("../output/output2.csv");
            subject->test(n);
        }
    }

    


    return 0;
}
