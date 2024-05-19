// DS051.cpp MyCircularQueue 만들기
#include <iostream>
using namespace std;
typedef int Element;

class MyCircularQueue {
    private:
        int maxsize;
        int front;
        int rear;
        int count;
        Element* list;
    public:
        void initialize();
        bool isEmpty() const;
        bool isFull() const;
        void enqueue(const Element&);
        void dequeue();
        Element Front() const;
        Element Rear() const;
        MyCircularQueue(int = 10);
        ~MyCircularQueue();
        void print() const;       // queue 만 출력
        int size() const;
        void printDetail() const;     // 4줄 모두 출력
};

void MyCircularQueue::initialize() {
    front = 0;
    rear = 0;
    count = 0;
}

bool MyCircularQueue::isEmpty() const {
    return (count == 0);

}

bool MyCircularQueue::isFull() const {
    return (count == maxsize);
    
}

void MyCircularQueue::enqueue(const Element& e) {
    if (isFull()) {
        cout << "=> Queue is Full !" << endl;
        return ;
    }
    list[rear] = e;
    rear = (rear + 1) % maxsize;
    count++;
}

void MyCircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "=> Queue is empty !" << endl;
        return ;
    }
    front = (front + 1) % maxsize;
    count--;
}

Element MyCircularQueue::Front() const{
    if (isEmpty()) {
        return 0;
    }
    return front;
}

Element MyCircularQueue::Rear() const {
    if (isEmpty()) {
        return 0;
    }
    return (rear + maxsize - 1) % maxsize;
}

MyCircularQueue::MyCircularQueue(int size) {
    maxsize = size;
    list = new Element[maxsize];
    initialize();
}

MyCircularQueue::~MyCircularQueue() {
    delete[] list;
}

void MyCircularQueue::print() const {
    cout << "Queue : ";
    for (int i = 0; i < count; i++)
        cout << "[" << list[(front + i) % maxsize] << "]";
    cout << endl;
}

int MyCircularQueue::size() const {
    return count;
}

void MyCircularQueue::printDetail() const {
    cout << "Size : " << size() << endl;
    print();
    cout << "index : " << endl;
    cout << "front : " << Front() << ", rear : " << Rear() << endl;
}   

int main() {
    MyCircularQueue q1(10);

    // dequeue 1번
    cout << "===== Dequeue x 1 =====" << endl;
    q1.dequeue();
    q1.printDetail();

    // enqueue 7번
    cout << "===== Enqueue x 7 (10 ~ 70)" << endl;
    for (int i = 0; i < 7; i++) 
        q1.enqueue((i + 1) * 10);
    q1.printDetail();

    // dequeue 3번
    cout << "===== Dequeue x 3 =====" << endl;
    for (int i = 0; i < 3; i++)
        q1.dequeue();
    q1.printDetail();

    // enqueue 6번
    cout << "===== Enqueue x 6 (10 ~ 60)" << endl;
    for (int i = 0; i < 6; i++) 
        q1.enqueue((i + 1) * 10);
    q1.printDetail();

    return 0;
}