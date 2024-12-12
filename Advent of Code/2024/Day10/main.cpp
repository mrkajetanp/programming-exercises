#include <fstream>
#include <iostream>
#include <print>
#include <set>
#include <string>
#include <utility>
#include <vector>

using Coord = std::pair<int, int>;

auto count_peaks(std::vector<std::string> &map, int row, int col,
                 std::set<Coord> &seen) -> int {
  if (map[row][col] == '9' && !seen.contains({row, col})) {
    seen.insert({row, col});
    return 1;
  }

  auto up = 0;
  if (row - 1 >= 0 && ((map[row - 1][col] - '0') - (map[row][col] - '0') == 1))
    up = count_peaks(map, row - 1, col, seen);

  auto down = 0;
  if (row + 1 < map.size() &&
      ((map[row + 1][col] - '0') - (map[row][col] - '0') == 1))
    down = count_peaks(map, row + 1, col, seen);

  auto left = 0;
  if (col - 1 >= 0 && ((map[row][col - 1] - '0') - (map[row][col] - '0') == 1))
    left = count_peaks(map, row, col - 1, seen);

  auto right = 0;
  if (col + 1 < map[0].size() &&
      ((map[row][col + 1] - '0') - (map[row][col] - '0') == 1))
    right = count_peaks(map, row, col + 1, seen);

  return up + down + left + right;
}

auto count_trails(std::vector<std::string> &map, int row, int col) -> int {
  if (map[row][col] == '9')
    return 1;

  auto up = 0;
  if (row - 1 >= 0 && ((map[row - 1][col] - '0') - (map[row][col] - '0') == 1))
    up = count_trails(map, row - 1, col);

  auto down = 0;
  if (row + 1 < map.size() &&
      ((map[row + 1][col] - '0') - (map[row][col] - '0') == 1))
    down = count_trails(map, row + 1, col);

  auto left = 0;
  if (col - 1 >= 0 && ((map[row][col - 1] - '0') - (map[row][col] - '0') == 1))
    left = count_trails(map, row, col - 1);

  auto right = 0;
  if (col + 1 < map[0].size() &&
      ((map[row][col + 1] - '0') - (map[row][col] - '0') == 1))
    right = count_trails(map, row, col + 1);

  return up + down + left + right;
}

auto trailhead_score(std::vector<std::string> &map) -> std::pair<int, int> {
  auto result_one = 0;
  auto result_two = 0;
  auto seen = std::set<Coord>();
  for (auto row = 0; row < map.size(); ++row) {
    for (auto col = 0; col < map[0].size(); ++col) {
      if (map[row][col] != '0')
        continue;
      result_one += count_peaks(map, row, col, seen);
      result_two += count_trails(map, row, col);
      // std::cout << "Got score: " << score << " for " << row << ',' << col
      //           << '\n';
      seen.clear();
    }
  }
  return std::make_pair(result_one, result_two);
}

auto main(int argc, char *argv[]) -> int {
  auto filename = argv[1];
  auto input = std::ifstream(filename);

  if (!input.is_open())
    return 1;

  // auto count = 0;

  auto lines = std::vector<std::string>();
  auto line = std::string();

  while (input) {
    std::getline(input, line);
    if (line.empty())
      break;
    lines.push_back(line);
  }

  auto result = trailhead_score(lines);
  std::cout << "Result one: " << result.first << '\n';
  std::cout << "Result two: " << result.second << '\n';

  return 0;
}
