#include <iostream>
using namespace std;

struct elem {
    int value;
};

class MyStack {
private:
    int maxsize;
    int top;
    elem* list;
public:
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void push(elem& e);
    elem* pop();
    void print() const;
    MyStack(int size = 5);  // 초기값 세팅
    ~MyStack();
};

MyStack::MyStack(int size) {
    maxsize = size;
    list = new elem[size];
    initialize();

    cout << "size: " << size << endl;
}

MyStack::~MyStack() {
    delete[] list;
}

void MyStack::initialize() {
    top = 0;
}

bool MyStack::isEmpty() const {
    return (top == 0) ? true : false;
    // return !top;
}

bool MyStack::isFull() const {
    return (maxsize == top) ? true : false;
}

void MyStack::push(elem& e) {
    if(isFull()) return ;
    list[top++] = e;
}

elem* MyStack::pop() {
    if (isEmpty()) return nullptr;
    return &list[--top];
}

void MyStack::print() const {
    for (int i = 0; i < top; i++)
        cout << list[i].value << endl;
}

int main() {
    elem one;
    elem* p;
    MyStack s1(10);
    
    one.value = 10; s1.push(one);
    one.value = 20; s1.push(one);
    one.value = 30; s1.push(one);
    s1.print();
    p = s1.pop();
    cout << p->value << endl;
    cout << "Stack list" << endl;

    s1.print();
    return 0;
}