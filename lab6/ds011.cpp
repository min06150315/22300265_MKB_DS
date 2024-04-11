// DS011. 입력한 수의 전체 합과 최대값 구하기
#include <iostream>
using namespace std;

int CalculateSum(int count, int *num);
int CalculateMax(int count, int *num);

int main()
{
    // 입력하고자 하는 숫자 입력 받기
    int count;
    cout << "Enter the number of numbers: ";
    cin >> count;
    int* num = new int[count];

    cout << CalculateSum(count, num) << " " << CalculateMax(count, num) << endl;

    delete[] num;
    return 0;
}

// 숫자 입력 받고 총합 구하기
int CalculateSum(int count, int *num)
{
    int sum = 0;
    for (int i = 0; i < count; i++){
        cout << "Enter the number: ";
        cin >> num[i];
        sum += num[i];
    }
    return sum;
}

// 최댓값 구하기
int CalculateMax(int count, int *num)
{
    int max = num[0];
    for (int i = 0; i < count - 1; i++)
        if (max < num[i + 1])
            max = num[i + 1];

    return max;
}