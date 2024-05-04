// DS033. 쿠폰 관리기
#include <iostream>
using namespace std;

struct elem {
    int rank;
    string name;
};

class CouponStack {
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
    CouponStack(int size = 10);  // 초기값 세팅
    ~CouponStack();
    void print() const;
    void rprint() const;
};

CouponStack::CouponStack(int size) {
    maxsize = size;
    list = new elem[size];
    initialize();
}

CouponStack::~CouponStack() {
    delete[] list;
}

void CouponStack::initialize() {
    top = 0;
}

bool CouponStack::isEmpty() const {
    return (top == 0) ? true : false;
    // return !top;
}

bool CouponStack::isFull() const {
    return (maxsize == top) ? true : false;
}

void CouponStack::push(elem& e) {
    if(isFull()) return ;
    list[top++] = e;
}

elem* CouponStack::pop() {
    if (isEmpty()) return nullptr;
    return &list[--top];
}

void CouponStack::print() const {
    for (int i = 0; i < top; i++)
        cout << list[i].rank << "등 - " << list[i].name << endl;
}

void CouponStack::rprint() const {
    //pop하고 출력
}

int main() {
    int s_size;
    cin >> s_size;
    CouponStack s1(s_size);
    elem* p;

    string menu;
    while (true) {
        cin >> menu;
        if (menu == "+") {

        } else if (menu == "-") {
            p = s1.pop();
            cout << p->rank << "등 - " << p->name << endl;
        } else if (menu == "q") {
            break;
        }
    }

    return 0;
}