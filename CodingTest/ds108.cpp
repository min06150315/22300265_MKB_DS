#include <iostream>
#include <vector>

using namespace std;

int main() {
  int size;
  cin >> size;

  vector<int> nums(size);
  for (int i = 0; i < size; ++i)
    cin >> nums[i];

  vector<int> count(nums.size(), 0);
  
  for (int i = 0; i < nums.size(); ++i) {
    int current = nums[i];
    if (count[i] == 0) {
      int cnt = 1;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] == current) {
          cnt++;
          count[j] = 1;
        }
      }
      cout << current << endl;
    }
  }

  return 0;
}
