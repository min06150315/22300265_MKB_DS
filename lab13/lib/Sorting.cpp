#include "Sorting.h"

void SelectionSort(Element list[], int n) {
    int i = 0, j = 0, min = 0, temp = 0;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (list[j] < list[min])
                min = j;
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
        PrintArray(list, n);
        for(int j = 0; j < n - i - 1; j++)
            if(list[j] > list[j + 1])
                swap(list[j], list[j + 1]);
    }
}

void BubbleSortDescending(Element list[], int n) {
    for(int i = 0; i < n - 1; i++) {
        PrintArray(list, n);
        for(int j = 0; j < n - i - 1; j++)
            if(list[j] < list[j + 1])
                swap(list[j], list[j + 1]);
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