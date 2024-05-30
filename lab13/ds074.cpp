// DS074. Quick sort
#include <iostream>
using namespace std;

typedef int Element;

void QuickSort(Element list[], int left, int right, int n);
void PrintArray(Element list[], int n);

int main() {
    Element list[64];
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
        cin >> list[i];
    QuickSort(list, 0, num - 1, num);

    return 0;
}

void QuickSort(Element list[], int left, int right, int n) {
    int pivot, i, j;
    if (left < right) {
        i = left;
        j = right+1; 
        pivot = list[left]; 
        do {
            do i++; while(i <= right && list[i] < pivot); 
            do j--; while(j > left && list[j] > pivot); 
            if(i < j)
                swap(list[i], list[j]);
#ifdef DEBUGMODE
            PrintArray(list, n);
#endif
        } while (i < j);
        swap(list[left], list[j]);
        
        QuickSort(list, left, j - 1, n);
        QuickSort(list, j + 1, right, n);
    }
}

void PrintArray(Element list[], int n) {
    for (int i = 0; i < n; i++)
        cout << "[" << list[i] << "] ";
    cout << endl;
}