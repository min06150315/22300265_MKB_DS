// DS016. prefix 문자열 구하기
#include <iostream>
#include <string>
using namespace std;

struct Str {
    string str1;
    string str2;
    string str3;
};

void inputSentence(Str* s);
string compareSentence(Str* s);

int main()
{
    Str* s1 = new Str;
    inputSentence(s1);
    cout << compareSentence(s1) << endl;
    delete s1;
    return 0;
}

// 한 문자열을 입력받아서 공백을 기준으로 나눠서 저장하기
void inputSentence(Str* s)
{
    string sentence;
    getline(cin, sentence);

    int len = sentence.length();
    int index[2];
    int count = 0;
    
    for (int i = 0; i < len; i++)
        if (sentence[i] == ' ')
            index[count++] = i;

    s->str1 = sentence.substr(0, index[0]);
    s->str2 = sentence.substr(index[0] + 1, index[1] - index[0] - 1);
    s->str3 = sentence.substr(index[1] + 1);
}

// prefix 문자열 구하기
string compareSentence(Str* s)
{
    string result;
    // 3개의 문자열의 각각의 길이 구하기
    int len1 = s->str1.length();
    int len2 = s->str2.length();
    int len3 = s->str3.length();
    
    // 3개의 문자열의 길이 중에 가장 짧은 길이 구하기
    int length = len1;

    if (len2 < length) 
        length = len2;

    if (len3 < length) 
        length = len3;

    // 가장 짧은 길이 만큼 반복하며 같은 문자가 있을 시에 result에 저장해놓기
    for (int i = 0; i < length; i++) {
        if (s->str1[i] == s->str2[i] && s->str1[i] == s->str3[i])
            result += s->str1[i];
        else    // 다른 문자가 나올시에 그만두기
            break;
    }
    // 세 단어 모두 시작하는 알파벳이 다를 때
    if (result.empty())
        result = "?";

    return result;
}