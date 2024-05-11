#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
    Student s1;
    s1.name = "min";
    s1.sid = "22300265";
    s1.initScore(3);
    s1.print();

    return 0;
}