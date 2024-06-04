// DS101. Sort machine
#include "./lib/Sorting.h"

int main() {
    Element list[64];
    int num;
    cin >> num;
    if (num < 1 || num > 500)
        return 0;

    for (int i = 0; i < num; i++)
        cin >> list[i];

    // Lab8의 라이브러리를 불러와 Selection Sorting으로 정렬하기
    SelectionSort(list, num);

    // 결과 출력
    for (int i = 0; i < num; i++)
        cout << list[i] << " ";
    cout << endl;
    return 0;
}