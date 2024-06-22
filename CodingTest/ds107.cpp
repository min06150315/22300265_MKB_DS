#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int size1, size2;

  cin >> size1 >> size2;

  int *list1 = new int[size1];
  int *list2 = new int[size2];

  for (int i = 0; i < size1; ++i)
    cin >> list1[i];

  for (int i = 0; i < size2; ++i)
    cin >> list2[i];

  int size3 = size1 + size2;
  int *list3 = new int[size3];

  for (int i = 0; i < size1; ++i)
    list3[i] = list1[i];

  for (int i = 0; i < size2; ++i)
    list3[size1 + i] = list2[i];

  sort(list3, list3 + size3, greater<int>());

  for (int i = 0; i < size3; ++i) {
    cout << list3[i] << " ";
  }
  cout << endl;

  delete[] list1;
  delete[] list2;
  delete[] list3;

  return 0;
}
