// DS001. 비만 판정하기
#include <iostream>
using namespace std;

void checkBMI(int height, int weight);

int main()
{
    int height, weight;
    
    // 유저애게 키, 몸무게 입력 받기
    cout << "Enter the height (cm, kg): ";
    cin >> height >> weight;
    
    checkBMI(height, weight);
    return 0;
}

// 입력 받은 키와 몸무게로 비만 판정
void checkBMI(int height, int weight)
{
    double bmi = weight / ((height * 0.01) * (height * 0.01));

    if (bmi >= 25) cout << "Yes" << endl;
    else cout << "No" << endl;
}