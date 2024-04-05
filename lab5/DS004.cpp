// DS004. 국영수 과목 점수를 입력받아 총점과 평균을 계산하고, 등급 판정
#include <iostream>
using namespace std;

struct st_score{
    int kor, eng, math;
    int total;
    double average;
};

void printGrade(int k, int e, int m);

int main()
{
    st_score s1;
    cout << "Enter the Korean, English and Math score (kor, eng, math): ";
    cin >> s1.kor >> s1.eng >> s1.math;

    s1.total = s1.kor + s1.eng + s1.math;
    s1.average = (double)s1.total / 3;

    cout << s1.total;
    printf(" %.1f\n", s1.average);

    printGrade(s1.kor, s1.eng, s1.math);
    return 0;
}

void printGrade(int k, int e, int m)
{
    string subject[] = {"Korean", "English", "Math"};
    int score[] = {k, e, m};

    for (int i = 0; i < 3; i++){
        cout << subject[i] << " - ";
        if (score[i] >= 70) cout << "Pass" << endl;
        else cout << "Fail" << endl;
    }
}