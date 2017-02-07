#include <iostream>

using std::string;
using std::cout;
using std::endl;

bool compare(string s1, string s2) {
  int sum1 = 0, sum2 = 0;
  for (auto & c : s1) {
    c = toupper(c);
    if (c < 65 || c > 90) {
      sum1 = 0;
      break;
    }
    sum1 += (int)c;
  }
  for (auto & c : s2) {
    c = toupper(c);
    if (c < 65 || c > 90) {
      sum2 = 0;
      break;
    }
    sum2 += (int)c;
  }
  return sum1 == sum2 ? true : false;
}

int main() {
  cout << compare("zD","BC") << endl;
  cout << compare("AD","DD") << endl;
  cout << compare("A1","") << endl;

  return 0;
}
