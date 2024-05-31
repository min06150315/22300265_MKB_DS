#ifndef S_H
#define S_H

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

#endif