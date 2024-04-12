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

// 문자열의 오른쪽 부분 자르기
void rtrim(string &s)
{
    // 뒤(last) 부터 탭과 공백(" \t")이 아닌(not) 부분 찾기
    size_t index = s.find_last_not_of(" \t");
    // 탭과 공백이 아닌 곳 까지 짜르기
    s = s.substr(0, index + 1);
}

// 문자열의 왼쪽 부분 자르기
void ltrim(string &s)
{
    // 앞(first) 부터 탭과 공백(" \t")이 아닌(not) 부분 찾기
    size_t index = s.find_first_not_of(" \t");
    // 탭과 공백이 아닌 문자열이 시작되는 부분만 남기기
    s = s.substr(index);
}