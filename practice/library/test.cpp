#include <iostream>
using namespace std;

class Student {
private:
    int *score;
    // int getSum();
    // double getAvg();
public:
    string name;
    string sid;
    void initScore(int size);
    void print() const;
};

void Student::initScore(int size ) {
    score = new int[size];
}

void Student::print() const {
    cout << "[" << sid << "] " << name << endl;
}

int main()
{
    Student s1;
    s1.name = "min";
    s1.sid = "22300265";
    s1.initScore(3);
    s1.print();

    return 0;
}