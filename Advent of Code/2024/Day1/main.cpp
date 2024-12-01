#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

auto list_distance(std::vector<int> &left, std::vector<int> &right) -> long {
  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());

  long sum = 0;
  for (int i = 0; i < left.size(); ++i) {
    sum += std::abs(left[i] - right[i]);
  }

  return sum;
}

auto similarity_score(std::vector<int> &left, std::vector<int> &right) -> long {
  std::map<int, int> counts;
  for (auto x : right)
    counts[x]++;

  long sum = 0;
  for (auto x : left)
    sum += x * counts[x];

  return sum;
}

auto main(int argc, char *argv[]) -> int {
  char *filename = argv[1];
  std::ifstream input(filename);

  if (!input.is_open())
    return 1;

  std::vector<int> left;
  left.reserve(1000);
  std::vector<int> right;
  right.reserve(1000);

  std::string line;
  while (input) {
    std::getline(input, line);
    if (line.empty())
      continue;
    int delimIdx = line.find(" ");
    left.push_back(std::stoi(line.substr(0, delimIdx)));
    while (std::isspace(line[++delimIdx]))
      ;
    right.push_back(std::stoi(line.substr(delimIdx)));
  }

  long distance = list_distance(left, right);
  std::cout << "distance: " << distance << '\n';

  long similarity = similarity_score(left, right);
  std::cout << "similarity: " << similarity << '\n';

  return 0;
}
