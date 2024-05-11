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
        this->next = nullptr;
    }
    friend class MyLinkedStack;
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
    MyLinkedStack();
    ~MyLinkedStack();
    void printAll();        // stack을 pop순서로 출력(pop은 하지 않음)
};

void MyLinkedStack::initialize() {
    // 현재 모든 스택을 비운다. (반복문)
    while (!isEmpty()) {
        //  1. temp node 생성
        Node* temp_Node;

        //  2. temp node에 stacktop 설정
        temp_Node = stacktop;

        //  3. stacktop에 stacktop의 next 설정
        stacktop = stacktop->next;

        //  4. temp node 삭제
        delete temp_Node;
    }
}

bool MyLinkedStack::isEmpty() const {
    return (stacktop == nullptr);
}

void MyLinkedStack::push(const int& e) {
    // 1. 새 Node 생성
    Node* new_Node;

    // 2. 새 Node에 new_element 값 설정
    new_Node = new Node(e);

    // 3. 새 Node의 링크에 Stacktop 추가
    new_Node->next = stacktop;

    // 4. Stacktop에 새 노드 주소 설정
    stacktop = new_Node;
}

void MyLinkedStack::pop() {
    // 1. isEmpty()이면 함수종료
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    // 2. temp node 생성
    Node* temp_Node;

    // 3. temp node에 stacktop 설정
    temp_Node = stacktop;

    // 4. stacktop에 stacktop의 next 설정
    stacktop = stacktop->next;

    // 5. temp node 삭제
    delete temp_Node;
}

int MyLinkedStack::peek() const {
    // 
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stacktop->data;
}

int MyLinkedStack::getNodeCnt() const {
    Node* temp_Node = stacktop;
    int count = 0;
    while (temp_Node != nullptr) {
        count++;
        temp_Node = temp_Node->next;
    }
    return count;
}

MyLinkedStack::MyLinkedStack() {
    stacktop = nullptr;
}

MyLinkedStack::~MyLinkedStack() {
    initialize();
}

void MyLinkedStack::printAll() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = stacktop;

    cout << temp->data ;
    temp = temp->next;

    while (temp != nullptr) {
        cout << " -> " << temp->data ;
        temp = temp->next;
    }
    cout << " (" << getNodeCnt() << " nodes)" << endl;
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
            cout << "Bye!" << endl; 
            break;
        }
    }

    return 0;
}