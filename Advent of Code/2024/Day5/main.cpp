#include <cmath>
#include <cstring>
#include <fstream>
#include <memory>
#include <print>
#include <regex>
#include <set>
#include <string>
#include <vector>

auto parse_rules(std::vector<std::string> &rules)
    -> std::unique_ptr<std::map<int, std::vector<int>>> {
  auto map = std::make_unique<std::map<int, std::vector<int>>>(
      std::map<int, std::vector<int>>());

  for (auto &rule : rules) {
    auto left = std::atoi(rule.substr(0, rule.find('|')).c_str());
    auto right = std::atoi(rule.substr(rule.find('|') + 1).c_str());
    (*map)[left].push_back(right);
  }

  return std::move(map);
}

auto find_idx(std::vector<int> &vec, int val) -> int {
  for (auto i = 0; i < vec.size(); ++i) {
    if (vec[i] == val)
      return i;
  }
  return -1;
}

auto update_valid(std::vector<int> &update,
                  std::map<int, std::vector<int>> *rules) -> bool {
  auto update_set = std::set<int>(update.begin(), update.end());
  for (auto i = 0; i < update.size(); ++i) {
    auto page = update[i];
    if (!rules->contains(page))
      continue;
    auto &page_rules = (*rules)[page];
    for (auto rule : page_rules) {
      if (!update_set.contains(rule))
        continue;
      if (find_idx(update, rule) < i)
        return false;
    }
  }
  return true;
}

auto update_find_invalid(std::vector<int> &update,
                         std::map<int, std::vector<int>> *rules) -> int {
  auto update_set = std::set<int>(update.begin(), update.end());
  for (auto i = 0; i < update.size(); ++i) {
    auto page = update[i];
    if (!rules->contains(page))
      continue;
    auto &page_rules = (*rules)[page];
    for (auto rule : page_rules) {
      if (!update_set.contains(rule))
        continue;
      if (find_idx(update, rule) < i)
        return i;
    }
  }
  return -1;
}

auto print_update(std::vector<int> &update) {
  std::print("[");
  for (auto x : update)
    std::print(" {}", x);
  std::println("]");
}

auto update_fix_invalid(std::vector<int> &update,
                        std::map<int, std::vector<int>> *rules) -> int {
  while (!update_valid(update, rules)) {
    auto invalid_idx = update_find_invalid(update, rules);
    if (invalid_idx > 0) {
      auto temp = update[invalid_idx];
      update[invalid_idx] = update[invalid_idx - 1];
      update[invalid_idx - 1] = temp;
    } else {
      break;
    }
  }

  return update[update.size() / 2];
}

auto validate_updates(std::vector<std::string> &updates,
                      std::map<int, std::vector<int>> *rules) -> int {
  auto result = 0;
  auto incorrect_fix_result = 0;
  auto num_regex = std::regex("(\\d+)");
  auto update = std::vector<int>();
  for (auto &line : updates) {
    // Collect pages into a vector
    auto num_begin = std::sregex_iterator(line.begin(), line.end(), num_regex);
    auto num_end = std::sregex_iterator();
    for (auto i = num_begin; i != num_end; ++i)
      update.push_back(std::atoi(i->str().c_str()));

    if (update_valid(update, rules))
      result += update[update.size() / 2];
    else
      incorrect_fix_result += update_fix_invalid(update, rules);

    // Validate the update vector
    update.clear();
  }
  std::println("Incorrect fix result: {}", incorrect_fix_result);
  return result;
}

auto main(int argc, char *argv[]) -> int {
  auto filename = argv[1];
  auto input = std::ifstream(filename);

  if (!input.is_open())
    return 1;

  auto count = 0;

  auto rules = std::vector<std::string>();
  auto updates = std::vector<std::string>();
  auto line = std::string();
  while (input) {
    std::getline(input, line);
    if (line.empty())
      break;
    rules.push_back(line);
  }

  while (input) {
    std::getline(input, line);
    if (line.empty())
      break;
    updates.push_back(line);
  }

  auto rules_map = parse_rules(rules);
  auto result = validate_updates(updates, rules_map.get());
  std::println("Result: {}", result);

  return 0;
}
