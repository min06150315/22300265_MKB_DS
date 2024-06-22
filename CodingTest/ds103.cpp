// DS103. 상 받는 최소 점수는?
#include <iostream>
#include "./lib/Sorting.h"

using namespace std;

int main() {
    int num, rank;
    cin >> num >> rank;

    int* list = new int[num];
   
    for (int i = 0; i < num; i++)
        cin >> list[i]; 
    
    SelectionSort(list, num);

    cout << list[rank - 1];

    delete[] list;
    return 0;
}
