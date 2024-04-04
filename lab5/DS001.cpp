// DS001. 비만 판정하기
#include <iostream>
using namespace std;

int main()
{
    int height, weight;
    double bmi;
    
    cout << "Enter the height (cm, kg): ";
    cin >> height;
    cin >> weight;
    
    bmi = weight / ((height * 0.01) * (height * 0.01));

    if (bmi >= 25){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
    
    return 0;
}