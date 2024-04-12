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

    // 불 필요한 공백, 탭 자르기
    rtrim(str);
    ltrim(str);

    cout << getWordLength(str) << endl;

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

// 문자열의 길이 리턴하기
int getWordLength(string &s)
{   
    // 문자열의 마지막 공백 찾기
    size_t space = s.find_last_of(" ");

    // 공백이 있을 때에
    if (space != string::npos){
        return s.length() - space - 1;
    }
    // 공백이 없을 때에 (한 단어 일때)
    return s.length();
}