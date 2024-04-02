// 2. 좌표 2개 입력받은 후 좌표간 거리 계산
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1;
    double x2, y2;
    double result;

    cout << "Enter the first coordinate: ";
    cin >> x1 >> y1;
    cout << "Enter the second coordinate: ";
    cin >> x2 >> y2;

    result = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    cout << result << endl;

    return 0;
}