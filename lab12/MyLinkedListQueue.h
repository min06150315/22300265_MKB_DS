#ifndef LLQ_H
#define LLQ_H

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
        void Rear() const;
        void Front() const;
        void printAll() const;
};

#endif LLQ_H