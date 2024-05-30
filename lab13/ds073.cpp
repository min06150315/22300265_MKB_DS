// DS073. Bubble sort
#include <iostream>
using namespace std;

typedef int Element;

void BubbleSortAscending(Element list[], int n);
void BubbleSortDescending(Element list[], int n);
void PrintArray(Element list[], int n);

int main() {
    Element list[64];
    Element temp[64];
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> list[i];
        temp[i] = list[i];
    }

    cout << "=== ascending order ===" << endl;
    PrintArray(list, num);
    BubbleSortAscending(list, num);

    cout << "=== descending order === " << endl;
    PrintArray(temp, num);
    BubbleSortDescending(temp, num);

    return 0;
}

void BubbleSortAscending(Element list[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++)
            if(list[j] > list[j + 1])
                swap(list[j], list[j + 1]);
#ifdef DEBUGMODE
        PrintArray(list, n);
#endif
    }
}

void BubbleSortDescending(Element list[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++)
            if(list[j] < list[j + 1])
                swap(list[j], list[j + 1]);
#ifdef DEBUGMODE
        PrintArray(list, n);
#endif
    }
}

void PrintArray(Element list[], int n) {
    for (int i = 0; i < n; i++)
        cout << "[" << list[i] << "] ";
    cout << endl;
}