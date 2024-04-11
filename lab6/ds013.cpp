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
    c1.list = new Menu[c1.count];

    for (int i = 0; i < c1.count; i++)
        addMenu(c1.list[i]);

    displayMenus(c1);

    return 0;
}

void addCafe(Cafe &r1)
{
    cout << "Enter the Cafe Name: ";
    getline(cin, r1.name);

    cout << "Enter the Number of Menu: ";
    cin >> r1.count;
}

void addMenu(Menu &m1)
{
    cout << "Enter the Menu and Price (menu, price): ";
    cin >> m1.name >> m1.price;
}

void displayMenus(Cafe &r1)
{
    cout << "===== " << r1.name << " =====" << endl;
    for (int i = 0; i < r1.count; i++)
        cout << r1.list[i].name << " " << r1.list[i].price << endl;
    cout << "=====================";
}