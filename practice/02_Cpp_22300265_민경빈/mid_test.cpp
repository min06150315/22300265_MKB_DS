#include <iostream>
using namespace std;

struct Major {
    string name;
    int credit;
    int score;
    int grade;
};

string GName[] = {"A+", "A0", "B+", "B0", "C+", "C0" ,"D+", "D0", "F"};

int main()
{
    int count;
    cin >> count;

    Major* m1 = new Major[count];

    for (int i = 0; i < count; i++) {
        cin >> m1[i].credit >> m1[i].name;
        getline(cin, m1->name);
    }
    print(m1, count);
}

double getGPA(Major &m){

}

void print(Major* m, int count){
    int totalCredit = 0;
    int GPA = getGPA(*m);
    int top = getHighScore(*m);

    for (int i = 0; i < count; i++) {
        cout << m[i].name << " " << m[i].credit << endl;
        totalCredit += m[i] .credit;
    }
    cout << "==========" << endl;
    cout << "Total Credit: " << totalCredit << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Top class: " << endl;
}

int getHighScore(Major &m){

}