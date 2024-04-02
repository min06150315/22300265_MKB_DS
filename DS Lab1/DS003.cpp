// 3. 날짜(월,일)를 입력받아 1년 중 몇번째 날인지 계산
#include <iostream>
using namespace std;

int main()
{
    int month, day;
    int day_count = 0;
    int dateMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cout << "Enter the date(month, day): ";
    cin >> month >> day;

    for (int i = 0; i < month - 1; i++){
        day_count = day_count + dateMonth[i];
    }

    day_count = day_count + day;

    cout << day_count << endl;

    return 0;
}