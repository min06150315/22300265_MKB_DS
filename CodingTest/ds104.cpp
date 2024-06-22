// DS104. Sorting with inked list (ver.1)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* start = nullptr;
Node* last = nullptr;

void swapNode(Node* x, Node* y) {
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

Node* createNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void addLast(int y) {
    Node* newNode = createNode(y);
    if (start == nullptr) {
        start = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

void printLinked() {
    Node* temp = start;
    while (temp->next != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void clearLinked() {
    Node* temp;
    while (start != nullptr) {
        temp = start;
        start = start->next;
        delete temp;
    }
    start = nullptr;
    last = nullptr;
}

void init(int size) {
    int number;
    clearLinked();
    for (int i = 0; i < size; i++) {
        cin >> number;
        addLast(number);
    }
}

void selectionLinked() {
    Node* key;
    Node* temp;
    
    key = start;
    while (key != nullptr) {
        temp = key->next;
        while (temp != nullptr) {
            if (key->data > temp->data) {
                swapNode(key, temp);
            }
            temp = temp->next;
        }
        key = key->next;
    }
}

int main() {
    int choice;
    cin >> choice;

    init(choice);
    selectionLinked();
    printLinked();

    return 0;
}
