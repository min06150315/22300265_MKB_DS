// DS002. 좌표 2개 입력받은 후 좌표간 거리 계산
#include <iostream>
#include <cmath>
using namespace std;

double calculateDistance(int x1, int y1, int x2, int y2);

int main()
{
    double x1, y1;
    double x2, y2;

    cout << "Enter the first coordinate (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the second coordinate (x2, y2): ";
    cin >> x2 >> y2;

    cout << calculateDistance(x1, y1, x2, y2) << endl;

    return 0;
}

double calculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}