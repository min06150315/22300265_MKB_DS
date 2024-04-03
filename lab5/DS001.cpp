// 1. 비만 판정하기
#include <iostream>
using namespace std;

int main()
{
    int height, weight;
    double bmi;
    
    cout << "Enter the height (cm): ";
    cin >> height;
    cout << "Enter the weight (kg): ";
    cin >> weight;
    
    bmi = weight / ((height / 100) * (height / 100));

    if (bmi >= 25){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    
    return 0;
}