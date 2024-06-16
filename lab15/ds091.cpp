// DS091. 사용자가 입력한 문자열 알아내기
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string StackSentence(string sen) {
    stack<char> s;
    string buffer;
    string result;

    for (char ch : sen) {
        if (ch == '<') {
            if (!s.empty()) {
                buffer.push_back(s.top());
                s.pop();
            }
        } else if (ch == '>') {
            if (!buffer.empty()) {
                s.push(buffer.back());
                buffer.pop_back();
            }
        } else {
            s.push(ch);
        }
    }

    while (!s.empty()) {
        buffer.push_back(s.top());
        s.pop();
    }
    
    reverse(buffer.begin(), buffer.end());
    result += buffer;

    return result;
}

int main() {
    while (true) {
        string sen;
        getline(cin, sen);

        if (sen == "q") {
            break;
        } else {
            string result = StackSentence(sen);
            cout << "=> " << result << endl;
        }
    }
    return 0;
}