// DS031. MyStack 만들기
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
    int s_size;
    cin >> s_size;
    MyStack s1(s_size);

    elem num;
    elem* p;
    string str;

    while (true) {
        cin >> str;
        if (str == "push") {
            cin >> num.value;
            s1.push(num);
        }else if (str == "pop") {
            p = s1.pop();
        }else if (str == "print") {
            s1.print();
            break;
        }
    }
    return 0;
}