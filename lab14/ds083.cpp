#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree(int *nums, int size) {
    if (nums == NULL) return NULL;

    if (nums[0] == 0) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < size) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < size && nums[i] != 0) {
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }
        i++;
        if (i < size && nums[i] != 0) {
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void maxHeapify(int* arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void insertValue(int* arr, int& size, int value) {
    int i = size;
    arr[size++] = value;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteValue(int* arr, int& size) {
    if (size <= 0) return;
    if (size == 1) {
        cout << "Delete " << arr[0] << endl;
        size--;
        return;
    }

    cout << "Delete " << arr[0] << endl;
    arr[0] = arr[size - 1];
    size--;
    maxHeapify(arr, size, 0);
}

void printHeap(int* arr, int size) {
    cout << "==> Heap : ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int size = 20;
    int count = 0;
    int* list = new int[size]();
    int menu;
    while (true) {
        cout << "1.insert 2.delete 3.print 4.quit > ";
        cin >> menu;

        switch (menu) {
            case 1: {
                int value;
                cout << "new value? ";
                cin >> value;
                insertValue(list, count, value);
                printHeap(list, count);
                break;
            }
            case 2:
                deleteValue(list, count);
                printHeap(list, count);
                break;
            case 3:
                printHeap(list, count);
                break;
            case 4:
                cout << "Bye!" << endl;
                delete[] list;
                return 0;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    }

    return 0;
}
