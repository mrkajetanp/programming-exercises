// Copyright 2016 <Cajetan Puchalski>
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::to_string;

class SequenceSum {
 private:
  int count;
 public:
  explicit SequenceSum(int c);
  string showSequence();
};

SequenceSum::SequenceSum(int c) {
  count = c;
}

string SequenceSum::showSequence() {
  if (count < 0) return to_string(count) + "<0";
  if (!count) return "0=0";
  ostringstream oss ; oss << 0;
  for (int i = 1 ; i <= count ; i++)
    oss << "+" << i;
  oss << " = " << count * (count+1) / 2;
  return oss.str();
}

void tests() {
  SequenceSum seqsum1(6);
  SequenceSum seqsum2(-15);
  SequenceSum seqsum3(0);
  cout << seqsum1.showSequence() << endl;
  cout << seqsum2.showSequence() << endl;
  cout << seqsum3.showSequence() << endl;
}

int main() {
  tests();
return 0;
}
