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

void CouponStack::print() const {   // stack 전체 출력
    for (int i = 0; i < top; i++)
        cout << list[i].rank << "등 - " << list[i].name << endl;
}

void CouponStack::rprint() const {  // stack pop하면서 전체 출력
    CouponStack tempStack(top);
    for (int i = 0; i < top; i++)
        tempStack.list[i] = list[i];
    tempStack.top = top;

    // 임시 스택을 pop하며 출력
    while (!tempStack.isEmpty()) {
        elem* p = tempStack.pop();
        cout << p->rank << " Rank - " << p->name << endl;
    }
}

int main() {
    int s_size;
    cin >> s_size;
    CouponStack s1(s_size);
    elem* p;
    elem temp;

    string menu;
    while (true) {  // q를 입력할 때까지 반복
        cin >> menu;
        if (menu == "+") {  // +: stack에 <쿠폰정보>에 해당하는 쿠폰 구조체를 만들어 push한다.
            cin >> temp.rank;
            getline(cin, temp.name);
            s1.push(temp);
        } else if (menu == "-") {   // -: stack에서 마지막으로 넣은 쿠폰을 꺼내어, 쿠폰정보를 출력한다.
            p = s1.pop();
            if (p != nullptr)
                cout << p->rank << " Rank - " << p->name << endl;
        } else if (menu == "q") {
            break;
        }
    }

    return 0;
}