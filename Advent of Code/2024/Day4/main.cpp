#include <cstring>
#include <fstream>
#include <iterator>
#include <print>
#include <regex>
#include <string>
#include <vector>

auto count_xmas(std::string &line) -> int {
  auto xmas_regex = std::regex("XMAS");
  auto xmas_begin = std::sregex_iterator(line.begin(), line.end(), xmas_regex);
  auto xmas_end = std::sregex_iterator();
  auto samx_regex = std::regex("SAMX");
  auto samx_begin = std::sregex_iterator(line.begin(), line.end(), samx_regex);
  auto samx_end = std::sregex_iterator();
  return std::distance(xmas_begin, xmas_end) +
         std::distance(samx_begin, samx_end);
}

auto scan_for_xmas(std::vector<std::string> &lines) -> int {
  // Input is a square
  auto size = lines.size();

  auto count = 0;
  // Horizontal matches
  for (auto &line : lines)
    count += count_xmas(line);

  // Vertical matches
  auto buf = std::string();
  buf.reserve(size);
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j)
      buf.push_back(lines[j][i]);
    count += count_xmas(buf);
    buf.clear();
  }

  // Diagonal right-to-left matches
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < i + 1; ++j)
      buf.push_back(lines[j][i - j]);
    count += count_xmas(buf);
    buf.clear();
  }
  for (auto i = 1; i < size; ++i) {
    for (auto j = 0; j < size - i; ++j)
      buf.push_back(lines[j + i][size - j - 1]);
    count += count_xmas(buf);
    buf.clear();
  }

  // Diagonal left-to-right matches
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < i + 1; ++j)
      buf.push_back(lines[i - j][size - j - 1]);
    count += count_xmas(buf);
    buf.clear();
  }

  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size - i - 1; ++j)
      buf.push_back(lines[size - j - 1][size - j - i - 2]);
    count += count_xmas(buf);
    buf.clear();
  }

  return count;
}

auto scan_for_x_mas(std::vector<std::string> &lines) -> int {
  auto count = 0;
  auto size = lines.size();

  for (auto row = 1; row < size - 1; ++row) {
    for (auto col = 1; col < size - 1; ++col) {
      if (lines[row][col] != 'A')
        continue;
      auto ul = lines[row - 1][col - 1];
      auto ur = lines[row - 1][col + 1];
      auto ll = lines[row + 1][col - 1];
      auto lr = lines[row + 1][col + 1];
      auto one = (ul == 'S' && lr == 'M') || (ul == 'M' && lr == 'S');
      auto two = (ur == 'S' && ll == 'M') || (ur == 'M' && ll == 'S');
      if (one && two)
        count++;
    }
  }

  return count;
}

auto main(int argc, char *argv[]) -> int {
  auto filename = argv[1];
  auto input = std::ifstream(filename);

  if (!input.is_open())
    return 1;

  auto count = 0;

  auto lines = std::vector<std::string>();
  auto line = std::string();
  while (input) {
    std::getline(input, line);
    if (line.empty())
      continue;
    lines.push_back(line);
  }
  auto result = scan_for_xmas(lines);
  std::println("Result XMAS: {}", result);

  result = scan_for_x_mas(lines);
  std::println("Result X-MAS: {}", result);
  return 0;
}
