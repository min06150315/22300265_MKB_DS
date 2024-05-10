// DS041. MyLinkedStack 만들기
#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
public:
    Node(int data) {     // constructor
        this->data = data;
        this->next = NULL;
    }
};

class MyLinkedStack {
private:
    Node* stacktop;
public:
    void initialize();
    bool isEmpty() const;
    void push(const int&);
    void pop();
    int peek() const;
    int getNodeCnt() const;     // node의 개수를 가져옴
    ~MyLinkedStack();
    void printAll();        // stack을 pop순서로 출력(pop은 하지 않음)
};

void MyLinkedStack::initialize() {
    int len = getNodeCnt();
    for (int i = 0; i < len; i++) {
        
    }
}

bool MyLinkedStack::isEmpty() const {

}

void MyLinkedStack::push(const int&) {

}

void MyLinkedStack::pop() {

}

int MyLinkedStack::peek() const {

}

int MyLinkedStack::getNodeCnt() const {

}

MyLinkedStack::MyLinkedStack() {
    initialize();
}

MyLinkedStack::~MyLinkedStack() {

}

void MyLinkedStack::printAll() {
    int len = getNodeCnt();
    for (int i = 0; i < len; i++) {
        
    }
}

int main() {
    MyLinkedStack s1;
    string menu;

    while (true) {
        cin >> menu;
        if (menu == "push") {   // stack에 새로운 Node를 생성하여 element를 추가함
            int num;
            cin >> num;
            s1.push(num);
        } else if (menu == "pop") {     // 내용을 출력하지는 않음
            s1.pop();
        } else if (menu == "peek") {    // 현재 stacktop에 있는 내용을 출력(pop하지는 않음)
            cout << s1.peek() << endl;
        } else if (menu == "print") {   // 모든 element를 출력
            s1.printAll();
        } else if (menu == "clear") {   // 스택 초기화
            s1.initialize();
        } else if (menu == "q") {   // 종료
            break;
        }
    }


}