// DS063. 카드 게임 대결
#include <iostream>
#include "MyLinkedListQueue.h"
using namespace std;

void cardGame(int n);

int main() {
    int menu;
    cin >> menu;
    
    cardGame(menu);

    return 0;
}

void cardGame(int n) {
    MyLinkedListQueue q1;
    int score1 = 0, score2 = 0;
    int Card1[n];
    int Card2[n];

    for (int i = 0; i < n; i++) {
        cin >> Card1[i];
        q1.enqueue(Card1[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> Card2[i];
        q1.enqueue(Card2[i]);
    }


    int temp1, temp2;
    int cur1, cur2;
    bool result;

    temp1 = q1.dequeue();
    temp2 = q1.dequeue();

    if (temp1 > temp2) {
        cout << "Round1 - P1 Win!" << endl;
        score1++;
        result = true;
    } else {
        cout << "Round1 - P2 Win1" << endl;
        score2++;
        result = false;
    }

    for (int i = 1; i < n; i++) {
        if (result == true) {
            cur1 = temp1;
            temp1 = q1.dequeue();
        }
    }
}