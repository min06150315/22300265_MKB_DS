#include <iostream>
using namespace std;

class MinHeap {
    private:
        int arr[30];
        int length;
    public:
        MinHeap();
        ~MinHeap();
        void insertKey(int value);
        int deleteKey();
        int peek();     // 최소값 리턴
        int size();     // node의 수 리턴
        bool isEmpty();     // node가 없는지 여부
        void minHeapifyUp(int index);       // index의 부모 방향으로 minheap 재구성
        void minHeapifyDown(int root = 0);     // root의 자식 방향으로 minheap 재구성
        void printHeap();       // 모든 노드값을 출력(level order traversal)
};

MinHeap::MinHeap() {
    length = 0;
}

MinHeap::~MinHeap() {}

void MinHeap::insertKey(int value) {
    if (length >= 30) {
        cout << "Heap is full" << endl;
        return;
    }
    arr[length] = value;
    length++;
    minHeapifyUp(length - 1);
}

int MinHeap::deleteKey() {
    if (length <= 0) {
        return -1;
    }
    if (length == 1) {
        length--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[length - 1];
    length--;
    minHeapifyDown(0);
    return root;
}

int MinHeap::peek() {
    if (length <= 0) {
        return -1;
    }
    return arr[0];
}

int MinHeap::size() {
    return length;
}

bool MinHeap::isEmpty() {
    return length == 0;
}

void MinHeap::minHeapifyUp(int index) {
    while (index != 0 && arr[(index - 1) / 2] > arr[index]) {
        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void MinHeap::minHeapifyDown(int root) {
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < length && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < length && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != root) {
        swap(arr[root], arr[smallest]);
        minHeapifyDown(smallest);
    }
}

void MinHeap::printHeap() {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    MinHeap heap;
    int menu;

    while (true) {
        cout << "1.Array to minHeap 2.insert 3.delete 4.print 0.quit > ";
        cin >> menu;

        if (menu == 1) {
            int size;
            cin >> size;
            int* list = new int[size];
            for (int i = 0; i < size; i++) {
                cin >> list[i];
                heap.insertKey(list[i]);
            }
            cout << "minHeap => ";
            heap.printHeap();
        } else if (menu == 2) {
            int value;
            cin >> value;
            heap.insertKey(value);
            cout << "minHeap => ";
            heap.printHeap();
        } else if (menu == 3) {
            int value = heap.deleteKey();
            if (value == -1) {
                cout << "Heap is empty." << endl;
            } else {
                cout << "min value: " << value << endl;
                cout << "minHeap => ";
            heap.printHeap();
            }
        } else if (menu == 4) {
            heap.printHeap();
        } else if (menu == 0) {
            cout << "bye!" << endl;
            break;
        }
    }

    return 0;
}
