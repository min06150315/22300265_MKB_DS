// DS102. 최댓값을 만들자.
#include <iostream>
#include "./lib/Sorting.h"
using namespace std;

typedef int Element;

int main() {
    int n, k;
    cin >> n >> k;
    
    int* deck1 = new int[n];
    int* deck2 = new int[n];

    for (int i = 0; i < n; i++)
        cin >> deck1[i];
    
    for (int i = 0; i < n; i++)
        cin >> deck2[i];

    SelectionSort(deck1, n);
    
    for (int i = 0; i < k; i++) {
        if (deck1[i] < deck2[i]) {
            deck1[i] = deck2[i];
        } else {
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += deck1[i];
    cout << sum << endl;


    delete[] deck1;
    delete[] deck2;

    return 0;
}
