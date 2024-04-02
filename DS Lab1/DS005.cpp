// 5. 알파벳 개수 세기
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',  'Y', 'Z', ' '};
    int alphaNum[27];
    string sentence;

    // alphaNum 0으로 초기화
    for (int i = 0; i < 27; i++){
        alphaNum[i] = 0;
    }

    // 유저에게 문장 입력 받기
    cout << "Enter the sentence: ";
    getline(cin, sentence);

    // 문자열의 길이 구하기
    int len = sentence.length();

    // 문자열 모두 대문자로 변환하기
    for (int i = 0; i < len; i++){
        sentence[i] = toupper(sentence[i]);
    }

    // 알파벳 개수 세기
    for (int i = 0; i < len; i++){
        for (int j = 0; j < 27; j++){
            if (sentence[i] == alpha[j]){
                alphaNum[j]++;
            }
        }
    }

    // 결과 출력
    //  공백 출력
    cout << "blanks : " << alphaNum[26] << endl;

    //  알파벳 출력
    for (int i = 0; i < 26; i++){
        if (alphaNum[i] > 0){
            cout << alpha[i] << " : " << alphaNum[i] << endl;
        }
    }

    return 0;
}