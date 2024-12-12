#include <cmath>
#include <fstream>
#include <iostream>
#include <print>
#include <regex>
#include <set>
#include <string>
#include <utility>
#include <vector>

using u64 = unsigned long;

auto digits_number_even(u64 x) -> bool {
  return (static_cast<u64>(std::floor(std::log10(x))) + 1) % 2 == 0;
}

auto blink(u64 stone, u64 count) -> u64 {
  static auto cache = std::map<std::pair<u64, u64>, u64>();
  auto pair = std::make_pair(stone, count);
  if (cache.contains(pair))
    return cache[pair];

  auto result = static_cast<u64>(0);

  if (count == 1) {
    if (stone != 0 && digits_number_even(stone))
      result = 2;
    else
      result = 1;
  } else {
    if (stone == 0) {
      result = blink(1, count - 1);
    } else if (digits_number_even(stone)) {
      auto num = std::to_string(stone);
      auto half_size = num.length() / 2;
      auto stone_one = std::atol(num.substr(0, half_size).c_str());
      auto stone_two = std::atol(num.substr(half_size).c_str());
      result = blink(stone_one, count - 1) + blink(stone_two, count - 1);
    } else {
      result = blink(stone * 2024, count - 1);
    }
  }

  cache[pair] = result;
  return result;
}

auto count_stones(std::string input, int blinks) -> size_t {
  auto num_regex = std::regex("(\\d+)");
  auto nums_begin = std::sregex_iterator(input.begin(), input.end(), num_regex);
  auto nums_end = std::sregex_iterator();
  auto stones = std::vector<u64>();
  for (auto i = nums_begin; i != nums_end; ++i)
    stones.push_back(std::atol(i->str().c_str()));

  auto result = static_cast<u64>(0);
  for (auto x : stones)
    result += blink(x, blinks);

  return result;
}

auto main(int argc, char *argv[]) -> int {
  auto filename = argv[1];
  auto input = std::ifstream(filename);

  if (!input.is_open())
    return 1;

  auto line = std::string();
  std::getline(input, line);

  auto result = count_stones(line, 25);
  std::println("Result one: {}", result);
  auto result_two = count_stones(line, 75);
  std::println("Result two: {}", result_two);

  return 0;
}
