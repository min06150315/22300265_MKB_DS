// 7. 문장을 숫자로 변환하기 (버전1)
#include <iostream>
using namespace std;

int main()
{
    string sentence;
    int result = 0;

    char alpha[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int alphaNUm[] = {1, 5, 10, 50, 100, 500, 1000};

    // 유저에게 문장 입력 받기
    cout << "Enter the sentence: ";
    getline(cin, sentence);

    // 문장의 길이 구하기
    int len = sentence.length();

    // 문장에 맞는 수 찾아내서 계산하기
    for (int i = 0; i < len; i++){
        for (int j = 0; j < 7; j++){
            if (sentence[i] == alpha[j]){
                result = result + alphaNUm[j];
            }
        }
    }
    // 결과 출력
    cout << result << endl;

    return 0;
}