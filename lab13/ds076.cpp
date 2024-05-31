#include <iostream>
using namespace std;

typedef int Element;

void SelectionSort(Element list[], int n);
void InsertionSort(Element list[], int n);
void BubbleSortAscending(Element list[], int n);
void BubbleSortDescending(Element list[], int n);
void QuickSort(Element list[], int left, int right, int n);
void Merge(Element list[], Element sorted[], int low, int mid, int high, int n);
void MergeSort(Element list[], Element sorted[], int low, int high, int n);
void PrintArray(Element arr[], int n);

int main() {
    int menu;
    int count;
    while (true) {
        cout << "1.selection 2.insertion 3.bubble 4.quick 5.merge 6.exit > ";
        cin >> menu;
        if (menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5) {
            cout << "Enter count: ";
            cin >> count;
            Element* list = new Element[count];
            
            cout << "Enter numbers: ";
            for (int i = 0; i < count; i++)
                cin >> list[i];
            
            Element* temp = nullptr;
            Element* sorted = nullptr;

            switch (menu) {
            case 1:
                SelectionSort(list, count);
                break;
            case 2:
                InsertionSort(list, count);
                break;
            case 3:
                temp = new Element[count];
                for (int i = 0; i < count; i++)
                    temp[i] = list[i];
                
                cout << "=== ascending order ===" << endl;
                BubbleSortAscending(list, count);
                PrintArray(list, count);

                cout << "=== descending order === " << endl;
                BubbleSortDescending(temp, count);
                PrintArray(temp, count);
                delete[] temp;
                break;
            case 4:
                QuickSort(list, 0, count - 1, count);
                PrintArray(list, count);
                break;
            case 5:
                sorted = new Element[count];
                MergeSort(list, sorted, 0, count - 1, count);
                PrintArray(list, count);
                delete[] sorted;
                break;
            default:
                break;
            }
            delete[] list;
        } else if (menu == 6) {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}

void SelectionSort(Element list[], int n) {
    int i = 0, j = 0, min = 0, temp = 0;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[min])
                min = j;
        }
        swap(list[i], list[min]);
        PrintArray(list, n);
    }
}

void InsertionSort(Element list[], int n) {
    Element next;
    int i, j;
    for (i = 0; i < n; i++) {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
            list[j + 1]= list[j];
        list[j + 1] = next;
        PrintArray(list, n);
    }
}

void BubbleSortAscending(Element list[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++)
            if(list[j] > list[j + 1])
                swap(list[j], list[j + 1]);
        PrintArray(list, n);
    }
}

void BubbleSortDescending(Element list[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++)
            if(list[j] < list[j + 1])
                swap(list[j], list[j + 1]);
        PrintArray(list, n);
    }
}

void QuickSort(Element list[], int left, int right, int n) {
    int pivot, i, j;
    if (left < right) {
        i = left;
        j = right + 1; 
        pivot = list[left]; 
        do {
            do i++; while(i <= right && list[i] < pivot); 
            do j--; while(j > left && list[j] > pivot); 
            if(i < j)
                swap(list[i], list[j]);
            PrintArray(list, n);
        } while (i < j);
        swap(list[left], list[j]);
        
        QuickSort(list, left, j - 1, n);
        QuickSort(list, j + 1, right, n);
    }
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
    PrintArray(list, n);
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