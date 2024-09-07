#include <string>

namespace log_line {
std::string message(std::string line) {
  auto split_idx = line.find("]: ");
  return line.substr(split_idx + 3);
}

std::string log_level(std::string line) {
  auto split_idx = line.find("]: ");
  return line.substr(1, split_idx - 1);
}

std::string reformat(std::string line) {
  return message(line) + " (" + log_level(line) + ")";
}
} // namespace log_line
