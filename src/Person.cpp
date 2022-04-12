#include "Person.h"

int Person::getIndex() const {
    return index;
}

std::string Person::getFirstname() const {
    return firstname;
}

std::string Person::getLastname() const {
    return lastname;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Person(" << p.getIndex() << ", " << p.getFirstname() << ", " << p.getLastname() << ")";
    return os;
}