// DS052. MyCircularQueue를 이용한 명령어 처러기
#include <iostream>
#include "MyCircularQueue.h"
using namespace std;

int main() {
    int size;
    cin >> size;
    MyCircularQueue q1(size);

    int menu;
    while (true) {
        cin >> menu;
        switch (menu)
        {
        case 'en':
            int num;
            cin >> num;
            q1.enqueue(num);
            break;
        
        case 'de':
            q1.dequeue();
            break;

        case 'front':
            q1.Front();
            break;

        case 'rear':
            q1.Rear();
            break;

        case 'size':
            q1.size();
            break;

        case 'empty':
            if (q1.isEmpty()) {
                cout << "=> 0" << endl;
            } else {
                cout << "=> 1" << endl;
            }
            break;

        case 'print':
            q1.print();
            break;

        case 'q':
            exit(-1);
            break;
        default:
            break;
        }
    }


    return 0;
}