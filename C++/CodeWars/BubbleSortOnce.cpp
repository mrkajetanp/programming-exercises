// Copyright 2016 <Cajetan Puchalski>
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::swap;
using std::vector;
using std::copy;
using std::ostream_iterator;
using std::iter_swap;

template <class Iterator>
inline void BubbleSort(Iterator begin, Iterator end) {
    for (Iterator i = begin; i+1 != end; ++i)
        if (*i > *(i+1))
            iter_swap(i, i+1);
}

vector<int> bubbleSortOnce(vector<int> input) {
  vector<int> result = input;
  BubbleSort(result.begin(), result.end());
  return result;
}

int main() {
  vector<int> expected = { 7, 5, 3, 1, 2, 4, 6, 8, 9 };
  // printing a vector
  copy(expected.begin(), expected.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  vector<int> actual = bubbleSortOnce({ 9, 7, 5, 3, 1, 2, 4, 6, 8 });
  // printing a vector
  copy(actual.begin(), actual.end(), ostream_iterator<int>(cout, " "));

  return 0;
}
