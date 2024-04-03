// 6. 전공 3과목의 GPA 계산하기
#include <iostream>
using namespace std;

struct major{
    string name;
    int credit;
    int score;
    int grade;  // 0 ~ 8 (A+ ~ F)
};

string GNAME[] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
double GNUM[] = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};

int main()
{
    major s1[3];

    // 유저에게 입력 받기
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

    // grade 찾기
    for (int i = 0; i < 3; i++){
        if (s1[i].score >= 95){         // A+
            s1[i].grade = 0;
        }else if (s1[i].score >= 90){   // A0
            s1[i].grade = 1;
        }else if (s1[i].score >= 85){   // B+
            s1[i].grade = 2;
        }else if (s1[i].score >= 80){   // B0
            s1[i].grade = 3;
        }else if (s1[i].score >= 75){   // C+
            s1[i].grade = 4;
        }else if (s1[i].score >= 70){   // C0
            s1[i].grade = 5;
        }else if (s1[i].score >= 65){   // D+
            s1[i].grade = 6;
        }else if (s1[i].score >= 60){   // D0
            s1[i].grade = 7;
        }else {
            s1[i].grade = 8;
        }
    }

    // 총 학점 수, 그레이드 평균 값 구하기
    int sum = 0;
    double avg = 0;

    for (int i = 0; i < 3; i++){
        sum = sum + s1[i].credit;
    }
    avg = ((GNUM[s1[0].grade] * s1[0].credit) + (GNUM[s1[1].grade] * s1[1].credit) + (GNUM[s1[2].grade] * s1[2].credit)) / sum;
    // 결과 출력하기
    for (int i = 0; i < 3; i++){
        cout << s1[i].name << "(" << s1[i].credit << ")" << " " << GNAME[s1[i].grade];
        printf(" %.1f\n", GNUM[s1[i].grade]);
    }
    cout << "Total Credits " << sum << ", GPA ";
    printf("%.2f\n", avg);

    return 0;
}