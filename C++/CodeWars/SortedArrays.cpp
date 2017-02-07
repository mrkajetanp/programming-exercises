#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int nthSmallest(vector<vector<int>> arr, int n) {
  vector<int> numbers;
  numbers.push_back(arr[0][0]);
  for (auto& row : arr) {
    for (auto& col : row) {
      if (numbers.size() == 1 && numbers.at(0) > col)
        numbers.insert(numbers.begin(), col);
      else if (numbers.size() == 1 && numbers.at(0) < col)
        numbers.push_back(col);
      for (int i  = 0 ; i < (int)numbers.size() ; i++) {
        if (col < numbers.at(i)) {
          numbers.insert(numbers.begin()+i, col);
          break;
        }
      }
    }
  }
  for (auto& num : numbers) cout << num;
  cout << endl;
  return numbers[n-1];
}

int main() {
  int expected = 5;
  int actual = nthSmallest({ {1,5}, {2, 7}, {4,8,9} }, 5);
  if (expected == actual) cout << "It works!" << endl;
  return 0;
}
