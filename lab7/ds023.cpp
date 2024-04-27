// DS023. 쇼핑몰 상품 정보 관리
#include <iostream>
using namespace std;

class Product {
    private:
        string name;
        int price;
        int saleRate;
        string factory;
        string size;
    public:
        Product();
        Product(string name, int price, int saleRate, string factory, string size);
        void AddProduct(); 
        void print() const;
        int getSalePrice() const;
};

Product::Product() {
    name = "";
    price = 0;
    saleRate = 0;
    factory = "";
    size = "";
}

Product::Product(string name, int price, int saleRate, string factory, string size) {
    this->name = name;
    this->price = price;
    this->saleRate = saleRate;
    this->factory = factory;
    this->size = size;
}

void Product::AddProduct() {
    cin.ignore();
    getline(cin, name);
    cin >> price >> saleRate >> size >> factory;
}

void Product::print() const {
    cout << getSalePrice() << "\t(-" << saleRate << "%)\t" << name << "\t" << size << "\t" << factory << endl;
}

int Product::getSalePrice() const {
    return price - price * saleRate / 100;
}

int main()
{
    Product* p1 = new Product[64];
    int menu;
    int count = 0;

    while (true) {
        cout << "1. Add 2. List 3. Quit > ";
        cin >> menu;
        if (menu == 1)
            p1[count++].AddProduct();
        else if (menu == 2)
            for (int i = 0; i < count; i++)
                p1[i].print();
        else
            break;
    }

    delete[] p1;
    return 0;
}