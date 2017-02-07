// Copyright 2016 <Cajetan Puchalski>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::to_string;


string sumLength(vector<int> input) {
  int psum = 0, ncount = 0;
  bool ifZeroPositive = false;
  for (int a : input) {
    if (a > 0) psum += a;
    if (a < 0) ncount++;
    if (a == 0 && ifZeroPositive == false) {
      ncount++;
      ifZeroPositive = true;
    } else if (a == 0) { ifZeroPositive = false; }
    }
  return to_string(psum)+' '+to_string(ncount);
}

int main() {
  vector<int> testInput = {1, 2, 3, 4, -1, -2, -3};
  assert(sumLength(testInput) == "10 3");

  testInput = {1, 2, 3, 4, 0, -1, -2, -3};
  assert(sumLength(testInput) == "10 4");

  std::cout << "Correct!" << std::endl;

  return 0;
}
