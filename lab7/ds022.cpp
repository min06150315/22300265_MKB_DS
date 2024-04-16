// DS022. 졸업영어성적 판단하기
#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int LCscore;
        int RCscore;
    public:
        // 기본 생성자
        Student() {
            name = "";
            LCscore = 0;
            RCscore = 0;
        }

        // 입력받는 생성자
        Student CreateStudent()
        {
            getline(cin, name);
            while(true) {
                cout << "LC> ";
                cin >> LCscore;
                if (IsInRange(LCscore))
                    break;
            }
            while(true) {
                cout << "RC> ";
                cin >> RCscore;
                if (IsInRange(RCscore))
                    break;
            }
            return Student(name, LCscore, RCscore);
        }

        // 멤버변수 parameter가 있는 생성자
        Student(string name, int LCscore, int RCscore) {
            this->name = name;
            this->LCscore = LCscore;
            this->RCscore = RCscore;
        }

        // 점수 0~495 점수 유효성 체크 함수
        bool IsInRange(int score){
            return (score >= 0 && score <= 495) ? true : false;
        }

        // 출력 메소드
        void print() const {
            cout << "[" << name << "]" << endl;
            cout << "LC - " << LCscore << " " << PassOrFail(LCscore) << endl;
            cout << "RC - " << RCscore << " " << PassOrFail(RCscore) << endl;
            cout << "Total - " << LCscore + RCscore << endl;
        }

        // pass, fail 메소드
        string PassOrFail(int score) const {
            return (score >= 350) ? "Pass" : "Fail";
        }
};

int main()
{
    Student s1;

    s1.CreateStudent();
    s1.print();

    return 0;
}