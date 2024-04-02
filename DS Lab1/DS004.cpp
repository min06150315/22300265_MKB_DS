// 4. 국영수 과목 점수를 입력받아 총점과 평균을 계산하고, 등급 판정
#include <iostream>
using namespace std;

struct st_score{
    int kor, eng, math;
    int total;
    double average;
};


int main()
{
    st_score s1;
    cout << "Enter the Korean, English and Math score: ";
    cin >> s1.kor >> s1.eng >> s1.math;

    s1.total = s1.kor + s1.eng + s1.math;
    s1.average = (double)s1.total / 3;

    cout << s1.total;
    printf(" %.1f\n", s1.average);

    cout << "Korean - ";
    if (s1.kor >= 70){
        cout << "Pass" << endl;
    }else {
        cout << "Fail" << endl;
    }

    cout << "English - ";
    if (s1.eng >= 70){
        cout << "Pass" << endl;
    }else {
        cout << "Fail" << endl;
    }

    cout << "Math - ";
    if (s1.math >= 70){
        cout << "Pass" << endl;
    }else {
        cout << "Fail" << endl;
    }

    return 0;
}