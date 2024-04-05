// DS008. 문장을 숫자로 변환하기 (버전2)
#include <iostream>
using namespace std;

int invertNum(string str);

int main()
{
    string sentence;
    int result = invertNum(sentence);
    cout << result << endl;
    return 0;
}

int invertNum(string str)
{
    int result = 0;
    char alpha[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int alphaNum[] = {1, 5, 10, 50, 100, 500, 1000};

    cout << "Enter the sentence: ";
    getline(cin, str);

    int len = str.length();
    
    for (int i = 0; i < len; i++){
        for (int j = 0; j < 7; j++){
            if (str[i] == alpha[j]){
                result = result + alphaNum[j];
                // Rule 1
                if ((str[i] == 'I' && str[i + 1] == 'V') || (str[i] == 'I' && str[i + 1] == 'X')){
                    result = result - alphaNum[j] * 2;
                }
                // Rule 2
                if ((str[i] == 'X' && str[i + 1] == 'L') || (str[i] == 'X' && str[i + 1] == 'C')){
                    result = result - alphaNum[j] * 2;
                }
                // Rule 3
                if ((str[i] == 'C' && str[i + 1] == 'D') || (str[i] == 'C' && str[i + 1] == 'M')){
                    result = result - alphaNum[j] * 2;
                }
            }
        }
    }
    return result;
}