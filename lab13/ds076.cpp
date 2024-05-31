#include "Sorting.h"

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
            
            Element* temp;
            Element* sorted;

            switch (menu) {
            case 1:
                PrintArray(list, count);
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
        } else if (menu == 6){
            cout << "bye!" << endl;
            break;
        }
    }
    return 0;
}