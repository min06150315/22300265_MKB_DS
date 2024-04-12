// DS012. 구조체 비교하기
#include <iostream>
using namespace std;

struct item{
    string name;
    int price;
    string factory;
};

void inputItem(item* i);
void compareItem(item* i1, item* i2);
void toUpperCase(string* i);

int main()
{
    item* i1 = new item;
    item* i2 = new item;

    inputItem(i1);
    inputItem(i2);

    compareItem(i1, i2);

    delete i1;
    delete i2;
    return 0;
}

void inputItem(item* i)
{
    cin >> i->name >> i->price >> i->factory;
}

void compareItem(item* i1, item* i2)
{
    string temp1 = i1->name;
    string temp2 = i2->name;

    toUpperCase(&i1->name);
    toUpperCase(&i2->name);

    if (i1->name == i2->name && i1->price == i2->price && i1->factory == i2->factory)
        cout << temp1 << " is equal." << endl;
    else
        cout << temp1 << " and " << temp2 << " is not equal." << endl;
}

void toUpperCase(string* s1)
{
    for (int i = 0; i < s1->length(); i++)
        if ((*s1)[i] >= 'a' && (*s1)[i] <= 'z')
            (*s1)[i] = (*s1)[i] - 'a' + 'A';
}