// DS013. 카페 메뉴 관리하기
#include <iostream>
using namespace std;

struct Menu{
    string name;    // 메뉴명 (공백포함하지 않음)
    int price;      // 가격
};

struct Cafe{
    string name;    // 식당 이름 (공백포함)
    int count;      // 메뉴개수
    Menu* list;     // 메뉴 리스트 ( 포인터 변수)
};

void addCafe(Cafe &r1);
void addMenu(Menu &m1);
void displayMenus(Cafe &r1);

int main()
{
    Cafe c1;
    addCafe(c1);
    displayMenus(c1);
    delete[] c1.list;
    return 0;
}

void addCafe(Cafe &c)
{
    cout << "Enter the Cafe Name: ";
    getline(cin, c.name);

    cout << "Enter the Number of Menu: ";
    cin >> c.count;

    c.list = new Menu[c.count];

    for (int i = 0; i < c.count; i++)
        addMenu(c.list[i]);
}

void addMenu(Menu &c)
{
    cout << "Enter the Menu and Price (menu, price): ";
    cin >> c.name >> c.price;
}

void displayMenus(Cafe &c)
{
    cout << "===== " << c.name << " =====" << endl;
    for (int i = 0; i < c.count; i++)
        cout << c.list[i].name << " " << c.list[i].price << endl;
    cout << "=====================";
}