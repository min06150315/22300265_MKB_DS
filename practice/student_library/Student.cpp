#include "Student.h"

void Student::initScore(int size ) {
    score = new int[size];
}

void Student::print() const {
    cout << "[" << sid << "] " << name << endl;
}