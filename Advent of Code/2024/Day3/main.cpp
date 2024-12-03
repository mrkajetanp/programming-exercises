#include <cstring>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

auto compute_mul(std::string mul) -> int {
  auto mul_stripped = mul.substr(4, mul.length() - 5);
  auto separator_idx = mul_stripped.find(",");
  auto left = std::atoi(mul_stripped.substr(0, separator_idx).c_str());
  auto right = std::atoi(mul_stripped.substr(separator_idx + 1).c_str());
  return left * right;
}

auto scan_mul(std::string &input) -> int {
  std::regex mul_regex("(mul\\(\\d+,\\d+\\))");
  auto muls_begin = std::sregex_iterator(input.begin(), input.end(), mul_regex);
  auto muls_end = std::sregex_iterator();
  int result = 0;
  for (auto i = muls_begin; i != muls_end; ++i)
    result += compute_mul(i->str());
  return result;
}

auto scan_mul_conditional(std::string &input) -> int {
  std::regex mul_regex("(mul\\(\\d+,\\d+\\))|(don't\\(\\))|(do\\(\\))");
  auto muls_begin = std::sregex_iterator(input.begin(), input.end(), mul_regex);
  auto muls_end = std::sregex_iterator();
  int result = 0;
  bool enabled = true;
  for (auto i = muls_begin; i != muls_end; ++i) {
    auto curr = i->str();
    if (curr == "don't()") {
      enabled = false;
      continue;
    }
    if (curr == "do()") {
      enabled = true;
      continue;
    }
    if (enabled)
      result += compute_mul(curr);
  }
  return result;
}

auto main(int argc, char *argv[]) -> int {
  char *filename = argv[1];
  std::ifstream input(filename);

  if (!input.is_open())
    return 1;

  std::stringstream buffer;
  buffer << input.rdbuf();
  std::string data = buffer.str();

  int result = scan_mul(data);
  int result_conditional = scan_mul_conditional(data);

  std::cout << "Result: " << result << '\n';
  std::cout << "Result conditional: " << result_conditional << '\n';

  return 0;
}
