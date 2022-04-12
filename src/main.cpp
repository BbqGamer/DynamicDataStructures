#include <iostream>
#include "LinkedList.h"
#include "Person.h"
#include "includes.h"

int main() {
    
    Person p = Person(1, "John", "Doe");
    std::cout << p << std::endl;

    return 0;
}
