// DS032. GPA 분석하기
#include <iostream>
using namespace std;

struct elem {
    double gpa;
    string name;
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
    elem* e;
    cout << "Top GPA: " << list[top - 1].gpa << endl;
    for (int i = top - 1; i >= 0; i--)
        cout << list[i].name << endl;
}

int main() {
    MyStack s1(100);

    elem num;
    string str;
    double max = 0;

    while (true) {
        cin >> num.gpa;
        if (num.gpa == 0) {
            s1.print();
            break;
        }
        cin >>  num.name;
        if (num.gpa > max) {
            max = num.gpa;
            s1.initialize();
            s1.push(num);
        } else if (num.gpa == max)
            s1.push(num);
    }

    return 0;
}