// DS062. 피보나치 수 구하기
#include <iostream>
#include "MyLinkedListQueue.h"
using namespace std;

void fibonacci(int n);

int main() {
    int num;
    cin >> num;

    fibonacci(num);

    return 0;
}

void fibonacci(int n) {
    MyLinkedListQueue q1;
    int result;
    if (n == 1) {
        q1.enqueue(1);
    } else if (n == 2) {
        q1.enqueue(1);
        q1.enqueue(1);
    } else if (n > 2) {
        int num1 = 1, num2 = 1;
        q1.enqueue(num1);
        q1.enqueue(num1);
        for (int i = 3; i <= n; ++i) {
            result = num1 + num2;
            q1.enqueue(result);
            num1 = num2;
            num2 = result;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int temp = q1.dequeue();
        if (i == 1)
            cout << i << "st: " << temp << endl;
        else if (i == 2)
            cout << i << "nd: " << temp << endl;
        else if (i == 3)
            cout << i << "rd: " << temp << endl;
        else
            cout << i << "th: " << temp << endl;

        if (i == n)
            cout << "=> fibonacci(" << n << "): " << temp << endl;
    }
}