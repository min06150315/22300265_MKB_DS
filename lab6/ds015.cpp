// DS015. 마지막 단어의 길이 구하기
#include <iostream>
#include <string>
using namespace std;

void rtrim(string &s);
void ltrim(string &s);
int getWordLength(string &s);

int main()
{
    string str;
    getline(cin, str);
    rtrim(str);
    ltrim(str);
    cout << getWordLength(str) << endl;
    return 0;
}
// ds014.cpp의 rtrim, ltrim 함수 재사용
//  문자열의 오른쪽 부분 자르기
void rtrim(string &s)
{
    // 뒤(last) 부터 탭과 공백(" \t")이 아닌(not) 부분 찾기
    size_t index = s.find_last_not_of(" \t");
    // 탭과 공백이 아닌 곳 까지 짜르기
    s = s.substr(0, index + 1);
}

//  문자열의 왼쪽 부분 자르기
void ltrim(string &s)
{
    // 앞(first) 부터 탭과 공백(" \t")이 아닌(not) 부분 찾기
    size_t index = s.find_first_not_of(" \t");
    // 탭과 공백이 아닌 문자열이 시작되는 부분만 남기기
    s = s.substr(index);
}

// 문자열의 길이 리턴하기
int getWordLength(string &s)
{   
    // 마지막부터 공백 찾기
    size_t space = s.find_last_of(" ");

    // 공백이 찾았을 때에 때에
    if (space != string::npos)
        return s.length() - space - 1;
        
    // 공백이 없을 때에 (한 단어 일때) 문자열의 길이 출력
    return s.length();
}