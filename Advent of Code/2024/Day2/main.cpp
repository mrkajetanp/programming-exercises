#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

auto valid_pair(int curr, int prev, int direction) -> bool {
  if (direction == 0 && curr < prev)
    return false;
  if (direction == 1 && curr > prev)
    return false;
  int diff = std::abs(curr - prev);
  if (diff < 1 || diff > 3)
    return false;
  return true;
}

auto is_safe(std::vector<int> &states) -> bool {
  // -1 - unset, 0 - increasing, 1 - decreasing
  int direction = -1;
  if (states[1] > states[0])
    direction = 0;
  if (states[1] < states[0])
    direction = 1;

  for (int i = 1; i < states.size(); ++i) {
    int prev = states[i - 1];
    int curr = states[i];

    if (!valid_pair(curr, prev, direction))
      return false;
  }

  return true;
}

auto is_safe_dampened(std::vector<int> &states) -> bool {
  // Already safe
  if (is_safe(states))
    return true;

  for (int i = 0; i < states.size(); ++i) {
    std::vector<int> temp(states.begin(), states.end());
    temp.erase(temp.begin() + i);
    if (is_safe(temp))
      return true;
  }

  return false;
}

auto main(int argc, char *argv[]) -> int {
  char *filename = argv[1];
  std::ifstream input(filename);

  if (!input.is_open())
    return 1;

  int count = 0;

  std::string line;
  char buf[100];
  std::vector<int> states;
  while (input) {
    std::getline(input, line);
    if (line.empty())
      continue;

    std::strcpy(buf, line.c_str());
    states.clear();

    char *token = std::strtok(buf, " ");
    while (token) {
      states.push_back(std::stoi(token));
      token = std::strtok(nullptr, " ");
    }

    if (is_safe_dampened(states))
      count++;
  }

  std::cout << "Result: " << count << '\n';

  return 0;
}
