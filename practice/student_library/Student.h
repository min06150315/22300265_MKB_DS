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