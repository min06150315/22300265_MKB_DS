// DS093. 단어 정렬하기
//  vertor, find() 사용
//  1) 길이가 짧은 단어가 먼저 출력된다.
//  2) 길이가 같은 경우에는 사전(알파벳) 순서대로 앞에 나오는 단어가 먼저 출력된다.
//  3) 중복된 단어가 있는 경우에는 한 번만 출력한다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

void printSortingWords(vector<string>& words) {
    sort(words.begin(), words.end(), compare);

    vector<string> uniqueWords;
    for (const string& word : words) {
        if (find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) {
            uniqueWords.push_back(word);
        }
    }

    cout << endl;
    for (const string& word : uniqueWords) {
        cout << word << endl;
    }
}

int main() {
    int size;
    cin >> size;

    vector<string> words(size);

    for (int i = 0; i < size; i++)
        cin >> words[i];

    printSortingWords(words);

    return 0;
}