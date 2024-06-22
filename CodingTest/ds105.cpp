// DS104. Sorting with inked list (ver.2)
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    string name;
    Node* next;
};

Node* start = nullptr;
Node* last = nullptr;

void swapNode(Node* x, Node* y) {
    int temp_data = x->data;
    string temp_name = x->name;
    x->data = y->data;
    x->name = y->name;
    y->data = temp_data;
    y->name = temp_name;
}

Node* createNode(int data, const string& name) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->name = name;
    newNode->next = nullptr;
    return newNode;
}

void addLast(int data, const string& name) {
    Node* newNode = createNode(data, name);
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
    while (temp != nullptr) {
        cout << temp->data << " " << temp->name << endl;
        temp = temp->next;
    }
}

void clearLinked() {
    Node* temp;
    while (start != nullptr) {
        temp = start;
        start = start->next;
        delete temp;
    }
    last = nullptr;
}

void init(int size) {
    int number;
    string name;
    clearLinked();
    for (int i = 0; i < size; i++) {
        cin >> number >> name;
        addLast(number, name);
    }
}

void insertionLinked() {
    if (start == nullptr || start->next == nullptr)
        return;

    Node* sorted = nullptr;
    Node* current = start;

    while (current != nullptr) {
        Node* next = current->next;
        
        if (sorted == nullptr || current->data <= sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        
        current = next;
    }

    start = sorted;
}

Node* findMaxNode() {
    Node* temp = start;
    if (temp == nullptr) return nullptr;

    Node* maxNode = temp;
    while (temp != nullptr) {
        if (temp->data > maxNode->data) {
            maxNode = temp;
        }
        temp = temp->next;
    }
    return maxNode;
}

int main() {
    int num;
    cin >> num;

    init(num);

    insertionLinked();

        cout << "1>" << findMaxNode()->data << " " << findMaxNode()->name << endl;

    clearLinked();

    return 0;
}
