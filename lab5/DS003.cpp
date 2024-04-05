// DS003. 날짜(월,일)를 입력받아 1년 중 몇번째 날인지 계산
#include <iostream>
using namespace std;

int countDay(int m, int d);

int main()
{
    int month, day;
    
    cout << "Enter the date(month, day): ";
    cin >> month >> day;

    cout << countDay(month, day) << endl;

    return 0;
}

int countDay(int m, int d)
{
    int day_count = 0;
    int dateMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < m - 1; i++)
        day_count = day_count + dateMonth[i];

    day_count = day_count + d;
    return day_count;
}