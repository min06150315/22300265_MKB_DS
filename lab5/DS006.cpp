// DS006. 전공 3과목의 GPA 계산하기
#include <iostream>
using namespace std;

struct major{
    string name;
    int credit;
    int score;
    int grade;  // 0 ~ 8 (A+ ~ F)
};

void printGrade(major s1[3]);

string GNAME[] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
double GNUM[] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};
int SCORE[] = {95, 90, 85, 80, 75, 70, 65, 60};

int main()
{
    major s1[3];
    printGrade(s1);
    return 0;
}

void printGrade(major s1[3])
{
    cout << "Enter the first class Name: " ;
    getline(cin, s1[0].name);
    cout << "Enter the first class Credit and Score: ";
    cin >> s1[0].credit >> s1[0].score;

    cin.ignore();

    cout << "Enter the second class Name: " ;
    getline(cin, s1[1].name);
    cout << "Enter the second class Credit and Score: ";
    cin >> s1[1].credit >> s1[1].score;

    cin.ignore();

    cout << "Enter the third class Name: " ;
    getline(cin, s1[2].name);
    cout << "Enter the third class Credit and Score: ";
    cin >> s1[2].credit >> s1[2].score;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 8; j++){
            if (s1[i].score >= SCORE[j]){
                s1[i].grade = j;
                break;
            }
        }
    }

    int sum = 0;
    double avg = 0;

    for (int i = 0; i < 3; i++)
        sum = sum + s1[i].credit;
    avg = ((GNUM[s1[0].grade] * s1[0].credit) + (GNUM[s1[1].grade] * s1[1].credit) + (GNUM[s1[2].grade] * s1[2].credit)) / sum;

    for (int i = 0; i < 3; i++){
        cout << s1[i].name << "(" << s1[i].credit << ")" << " " << GNAME[s1[i].grade];
        printf(" %.1f\n", GNUM[s1[i].grade]);
    }
    cout << "Total Credits " << sum << ", GPA ";
    printf("%.2f\n", avg);
}