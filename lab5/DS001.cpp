// DS001. 비만 판정하기
// call by reference 사용하기
#include <iostream>
using namespace std;

void checkBMI(int height, int weight);

int main()
{
    int height, weight;
    
    cout << "Enter the height (cm, kg): ";
    cin >> height >> weight;
    
    checkBMI(height, weight);
    return 0;
}

void checkBMI(int height, int weight)
{
    double bmi = weight / ((height * 0.01) * (height * 0.01));

    if (bmi >= 25) cout << "Yes" << endl;
    else cout << "No" << endl;
}