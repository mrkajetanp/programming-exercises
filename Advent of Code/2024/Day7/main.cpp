#include <fstream>
#include <iostream>
#include <numeric>
#include <print>
#include <regex>
#include <set>
#include <string>
#include <utility>
#include <vector>

using u64 = unsigned long;

// Return 0 if the calibration is not valid
auto get_calibration(std::vector<u64> operands, u64 target) -> u64 {
  auto last = operands[operands.size() - 1];
  if (operands.size() == 1) {
    if (operands[0] == target)
      return target;
    else
      return 0;
  }

  if (target % last != 0) {
    auto temp_operands = std::vector<u64>(operands.begin(), operands.end() - 1);
    auto attempt_add = get_calibration(std::move(temp_operands), target - last);
    if (attempt_add + last == target)
      return target;
  } else {
    auto temp_operands = std::vector<u64>(operands.begin(), operands.end() - 1);
    auto attempt_add = get_calibration(std::move(temp_operands), target - last);
    if (attempt_add + last == target)
      return target;

    temp_operands = std::vector<u64>(operands.begin(), operands.end() - 1);
    auto attempt_mul = get_calibration(std::move(temp_operands), target / last);
    if (attempt_mul * last == target)
      return target;
  }

  return 0;
}

// Return 0 if the calibration is not valid
auto get_calibration_concat(std::vector<u64> operands, u64 target) -> u64 {
  auto target_str = std::to_string(target);
  auto last = operands[operands.size() - 1];
  auto last_str = std::to_string(last);
  if (operands.size() == 1) {
    if (operands[0] == target)
      return target;
    else
      return 0;
  }

  if (target % last != 0) {
    auto temp_operands = std::vector<u64>(operands.begin(), operands.end() - 1);
    if (get_calibration_concat(std::move(temp_operands), target - last))
      return target;

    if (target_str.ends_with(last_str)) {
      auto temp_operands =
          std::vector<u64>(operands.begin(), operands.end() - 1);
      auto temp_target = std::atol(
          target_str.substr(0, target_str.length() - last_str.length())
              .c_str());
      if (get_calibration_concat(std::move(temp_operands), temp_target))
        return target;
    }
  } else {
    auto temp_operands = std::vector<u64>(operands.begin(), operands.end() - 1);
    if (get_calibration_concat(std::move(temp_operands), target - last))
      return target;

    temp_operands = std::vector<u64>(operands.begin(), operands.end() - 1);
    if (get_calibration_concat(std::move(temp_operands), target / last))
      return target;

    if (target_str.ends_with(last_str)) {
      auto temp_target = std::atol(
          target_str.substr(0, target_str.length() - last_str.length())
              .c_str());
      auto temp_operands =
          std::vector<u64>(operands.begin(), operands.end() - 1);
      if (get_calibration_concat(std::move(temp_operands), temp_target))
        return target;
    }
  }

  return 0;
}

auto total_calibration(std::vector<std::string> &lines) -> std::pair<u64, u64> {
  u64 result = 0;
  u64 result_concat = 0;

  for (auto &line : lines) {
    auto colon_idx = line.find(':');
    auto target = std::atol(line.substr(0, colon_idx).c_str());

    auto operands_line = line.substr(colon_idx);
    auto operands = std::vector<u64>();
    auto num_regex = std::regex("(\\d+)");
    auto num_begin = std::sregex_iterator(operands_line.begin(),
                                          operands_line.end(), num_regex);
    auto num_end = std::sregex_iterator();
    for (auto i = num_begin; i != num_end; ++i)
      operands.push_back(static_cast<u64>(std::atol(i->str().c_str())));

    auto operands_concat = std::vector<u64>(operands.begin(), operands.end());
    result += get_calibration(std::move(operands), static_cast<u64>(target));
    result_concat += get_calibration_concat(std::move(operands_concat),
                                            static_cast<u64>(target));
  }

  return std::make_pair(result, result_concat);
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

  auto result = total_calibration(lines);
  std::cout << "Result one: " << result.first << '\n';
  std::cout << "Result two: " << result.second << '\n';

  return 0;
}
