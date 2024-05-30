// DS075. Merge sort
#include <iostream>

using namespace std;

typedef int Element;

void Merge(Element list[], Element sorted[], int low, int mid, int high, int n);
void MergeSort(Element list[], Element sorted[], int low, int high, int n);
void PrintArray(Element arr[], int n);

int main() {
    Element list[64];
    Element sorted[64];
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
        cin >> list[i];

#ifdef DEBUGMODE
    PrintArray(list, num);
#endif
    MergeSort(list, sorted, 0, num - 1 , num);

    return 0;
}

void Merge(Element list[], Element sorted[], int low, int mid, int high, int n) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (list[i]<= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    while (i <= mid)
        sorted[k++] = list[i++];

    while (j <= high)
        sorted[k++] = list[j++];

    for (i = low; i <= high; i++)
        list[i] = sorted[i];
#ifdef DEBUGMODE
    PrintArray(list, n);
#endif
}

void MergeSort(Element list[], Element sorted[], int low, int high, int n) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(list, sorted, low, mid, n);
        MergeSort(list, sorted, mid + 1, high, n);
        Merge(list, sorted, low, mid, high, n);
    }
}

void PrintArray(Element list[], int n) {
    for (int i = 0; i < n; i++)
        cout << "[" << list[i] << "] ";
    cout << endl;
}