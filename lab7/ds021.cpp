// DS021. 성적 계산하기
#include <iostream>
using namespace std;

class Student {
    private:
        double getAvg() const;
    public:
        string name;
        string sid;
        int* score;
        void print() const;
};

double Student::getAvg() const {
        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += score[i];
        return (double) sum / 3;
}

void Student::print() const {
            cout << "[" << sid << "] " << name << endl;
            cout << "The Average score is " << getAvg() << endl;
}

int main()
{
    Student s1;
    s1.score  = new int[3];
    
    cin >> s1.sid;

    for (int i = 0; i < 3; i++)
        cin >> s1.score[i];

    cin.ignore();
    getline(cin, s1.name);

    s1.print();

    delete[] s1.score;
    return 0;
}