// Copyright 2016 <Cajetan Puchalski>
#include <iostream>
#include <string>
#include <cassert>

using std::cout;
using std::endl;
using std::string;

int content_weight(int bottle_weight, string scale_string) {
  int scale = stoi(scale_string.substr(0, scale_string.find(" ")));
  int typePos = scale_string.find("times") + 6;
  bool ifLarger = scale_string.substr(typePos, scale_string.length() - typePos) == "larger";
  int value = bottle_weight / (scale + 1);
  return ifLarger ? value * scale : value;
}

int main() {
  assert(content_weight(120, "2 times larger") == 80);
  assert(content_weight(120, "2 times smaller") == 40);

  return 0;
}

/*
* Takes a bottle_weight and scale of the bottle to its contents
* and returns the weight of its contents
* @param {int} bottleWeight:
*  The weight of the entire bottle and contents
* @param {string} scale:
*  A string comparing the weight of the bottle contents to the weight of the bottle by itself
*  Acceptable values: ('2 times larger', '4 times larger', '50 times smaller', etc..)
*/
