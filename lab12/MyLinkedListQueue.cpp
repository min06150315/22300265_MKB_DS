#include "MyLinkedListQueue.h"

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

void MyLinkedListQueue::Rear() const {
    if (isempty())
        cout << "Queue is empty." << endl;
    else 
        cout << "element at rear: " << rear->data << endl;
}

void MyLinkedListQueue::Front() const {
    if (isempty())
        cout << "Queue is empty." << endl;
    else
        cout << "element at front: " << front->data << endl;
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
