// 5. 알파벳 개수 세기
#include <iostream>
#include <cctype>
using namespace std;;

void printAlpha(string s);

char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',  'Y', 'Z', ' '};
int alphaNum[27];

int main()
{
    string sentence;

    cout << "Enter the sentence: ";
    getline(cin, sentence);

    printAlpha(sentence);
    return 0;
}

void printAlpha(string s)
{
    int len = s.length();

    for (int i = 0; i < len; i++)
        s[i] = toupper(s[i]);
    for (int i = 0; i < 27; i++)
        alphaNum[i] = 0;

    for (int i = 0; i < len; i++)
        for (int j = 0; j < 27; j++)
            if (s[i] == alpha[j]) 
                alphaNum[j]++;

    cout << "blanks : " << alphaNum[26] << endl;

    for (int i = 0; i < 26; i++)
        if (alphaNum[i] > 0) 
            cout << alpha[i] << " : " << alphaNum[i] << endl;
}