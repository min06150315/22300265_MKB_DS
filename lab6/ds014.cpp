// DS014. 문장의 앞뒤 공백 제거하기
#include <iostream>
#include <string>
using namespace std;

void rtrim(string &s);
void ltrim(string &s);

int main()
{
    string s1;
    getline(cin, s1);

    rtrim(s1);
    ltrim(s1);
    cout << s1 << endl;
    return 0;
}

void rtrim(string &s)
{
    // 뒤 부터 탭과 공백이 아닌 부분 찾기
    size_t index = s.find_last_not_of(" \t");
    s = s.substr(0, index + 1);
}

void ltrim(string &s)
{
    // 앞 부터 탭과 공백이 아닌 부분 찾기
    size_t index = s.find_first_not_of(" \t");
    s = s.substr(index);
}