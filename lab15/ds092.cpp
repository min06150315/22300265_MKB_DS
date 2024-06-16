// DS092. 배열에서 K번째 가장 큰 수 찾기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int size, k;
    cin >> size >> k;

    vector<int> list(size);
    for (int i = 0; i < size; i++)
        cin >> list[i];

    priority_queue<int> maxHeap(list.begin(), list.end());

    for (int i = 0; i < k - 1; i++)
        if (!maxHeap.empty())
            maxHeap.pop();

    if (!maxHeap.empty())
        cout << maxHeap.top() << endl;

    return 0;
}