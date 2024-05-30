// DS072. Insertion sort
#include <iostream>
using namespace std;

typedef int Element;

void InsertionSort(Element list[], int n);
void PrintArray(Element list[], int n);

int main() {
    Element list[64];
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
        cin >> list[i];

    InsertionSort(list, num);

    return 0;
}

void InsertionSort(Element list[], int n) {
    Element next;
    int i, j;
    for (i = 0; i < n; i++) {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
            list[j + 1]= list[j];
        list[j + 1] = next;
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