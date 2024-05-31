// DS071. Selection sort
#include <iostream>
using namespace std;

typedef int Element;

void SelectionSort(Element list[], int n);
void PrintArray(Element list[], int n);

int main() {
    Element list[64];
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
        cin >> list[i];

    PrintArray(list, num);
    
    SelectionSort(list, num);

    return 0;
}

void SelectionSort(Element list[], int n) {
    int i = 0, j = 0, min = 0, temp = 0;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (list[j] < list[min])
                min = j;
        swap(list[i], list[min]);
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