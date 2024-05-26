// DS061. MyLLQueue 만들기
#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    friend class MyLinkedListQueue;
};

class MyLinkedListQueue {
    private:
        Node* front;
        Node* rear;
    public:
        MyLinkedListQueue();
        ~MyLinkedListQueue();
        void initialize();
        void enqueue(const int&);
        void dequeue();
        bool isempty() const;
        int Rear() const;
        int Front() const;
        void printAll() const;
};
MyLinkedListQueue::MyLinkedListQueue() {
    front = NULL;
    rear = NULL;
}

MyLinkedListQueue::~MyLinkedListQueue() {
    initialize();
}

void MyLinkedListQueue::initialize() {
    while (front != NULL) {
        dequeue();
    }
    front = NULL;
    rear = NULL;
}

void MyLinkedListQueue::enqueue(const int& e) {
    Node* new_node = new Node(e);
    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void MyLinkedListQueue::dequeue() {
    if (isempty()) {
        cout << "Queue is Empty." << endl;
        return;
    } else {
        Node* ptr = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete ptr;
    }
}

bool MyLinkedListQueue::isempty() const {
    return front == NULL;
}

int MyLinkedListQueue::Rear() const {
    if (isempty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return rear->data;
}

int MyLinkedListQueue::Front() const {
    if (isempty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return front->data;
}

void MyLinkedListQueue::printAll() const {
    if (isempty()) {
        cout << "Queue is empty." << endl;
    } else {
        Node* ptr = front;
        
        cout << ptr->data;
        ptr = ptr->next;
        
        while (ptr != NULL) {
            cout  << " -> " << ptr->data;
            ptr = ptr->next; 
        }
        cout << endl;
    }
}

int main() {
    MyLinkedListQueue q1;

    int choice, flag = 1, value;

    while( flag == 1) {
        cout << "\n1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue 6.exit > ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter a Value: ";
                cin >> value;
                q1.enqueue(value);
                break;
            case 2: 
                q1.dequeue();
                break;
            case 3: 
                cout << "element at front: " << q1.Front() << endl;
                break;
            case 4:
                cout << "element at rear: " << q1.Rear() << endl;
                break;
            case 5:
                q1.printAll();
                break;
            case 6: 
                flag = 0;
                cout << "bye!" << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}