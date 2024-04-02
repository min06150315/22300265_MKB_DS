// 7. 문장을 숫자로 변환하기 (버전1)
#include <iostream>
using namespace std;

int main()
{
    string sentence;
    int result = 0;

    char alpha[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int alphaNUm[] = {1, 5, 10, 50, 100, 500, 1000};

    cout << "Enter the sentence: ";
    getline(cin, sentence);

    int len = sentence.length();

    for (int i = 0; i < len; i++){
        for (int j = 0; j < 7; j++){
            if (sentence[i] == alpha[j]){
                result = result + alphaNUm[j];
            }
        }
    }
    cout << result << endl;

    return 0;
}