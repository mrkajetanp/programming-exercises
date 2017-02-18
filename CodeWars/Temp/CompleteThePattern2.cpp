// Copyright 2016 <Cajetan Puchalski>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Pattern {
 public:
    static string pattern(int n);
};

string Pattern::pattern(int n) {
  if (n < 1) return "";
  string result, line;

  for (int i = n; i > 0; i--) {
    line += to_string(i);
    result.insert(0, line + "\n");
  }

  result.pop_back();
  return result;
}

int main() {
  int input = 4;
  string patt = Pattern::pattern(input);
  cout << patt << endl;
  return 0;
}
