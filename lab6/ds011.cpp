// DS011. 입력한 수의 전체 합과 최대값 구하기
#include <iostream>
using namespace std;

int CalculateSum(int count, int* num);
int CalculateMax(int count, int* num);

int main()
{
    int count;
    cin >> count;
    int* num = new int[count];

    cout << CalculateSum(count, num) << " " << CalculateMax(count, num) << endl;

    delete[] num;
    return 0;
}

int CalculateSum(int count, int* num)
{
    int sum = 0;
    for (int i = 0; i < count; i++){
        cin >> num[i];
        sum += num[i];
    }
    return sum;
}

int CalculateMax(int count, int* num)
{
    int max = num[0];
    for (int i = 0; i < count - 1; i++)
        if (max < num[i + 1])
            max = num[i + 1];

    return max;
}