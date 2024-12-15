#include <array>
#include <cmath>
#include <format>
#include <fstream>
#include <print>
#include <regex>
#include <set>
#include <string>
#include <vector>

using Coord = std::pair<int, int>;

class Robot {
public:
  Coord start_pos;
  Coord velocity;

  Robot(Coord start_pos, Coord velocity)
      : start_pos(start_pos), velocity(velocity) {}

  auto predict_position(int x_size, int y_size, int seconds) const -> Coord {
    auto x_coord =
        this->start_pos.first + (this->velocity.first * seconds) % x_size;
    auto y_coord =
        this->start_pos.second + (this->velocity.second * seconds) % y_size;

    if (x_coord < 0)
      x_coord += x_size;
    if (x_coord >= x_size)
      x_coord -= x_size;
    if (y_coord < 0)
      y_coord += y_size;
    if (y_coord >= y_size)
      y_coord -= y_size;

    return std::make_pair(x_coord, y_coord);
  }
};

void print_robots(std::set<Coord> &coords, int width, int height) {
  auto empty_line = std::string(width, ' ');
  auto map = std::vector<std::string>();
  for (auto i = 0; i < height; ++i)
    map.push_back(std::string(empty_line));
  for (auto &coord : coords)
    map[coord.second][coord.first] = '*';

  for (auto row = 0; row < map.size(); ++row) {
    for (auto col = 0; col < map[0].size(); ++col) {
      std::print("{}", map[row][col]);
    }
    std::println("");
  }
}

auto christmas_tree_search(std::vector<Robot> &robots, int width, int height)
    -> int {
  auto coords = std::set<Coord>();
  for (auto i = 1; i < width * height; ++i) {
    for (auto &robot : robots)
      coords.insert(std::move(robot.predict_position(width, height, i)));
    // std::println("It {} coords {} robots {}", i, coords.size(),
    // robots.size());
    if (coords.size() != robots.size()) {
      coords.clear();
      continue;
    }
    std::println("Iteration {}", i);
    print_robots(coords, width, height);
    coords.clear();
  }

  return width * height;
}

auto safety_factor(std::vector<std::string> &lines, int x_size, int y_size,
                   int seconds) -> int {
  auto result_one = 0;
  auto robot_regex = std::regex("p=(-?\\d+),(-?\\d+) v=(-?\\d+),(-?\\d+)");

  auto quadrants = std::array<int, 4>({0, 0, 0, 0});

  auto x_midpoint = x_size / 2;
  auto y_midpoint = y_size / 2;

  auto robots = std::vector<Robot>();

  for (auto &line : lines) {
    auto matches = std::smatch();
    if (std::regex_search(line, matches, robot_regex)) {
      auto start_pos = std::make_pair(std::atoi(matches[1].str().c_str()),
                                      std::atoi(matches[2].str().c_str()));
      auto velocity = std::make_pair(std::atoi(matches[3].str().c_str()),
                                     std::atoi(matches[4].str().c_str()));
      auto robot = Robot(std::move(start_pos), std::move(velocity));
      // std::println("Got pos {},{} velocity {},{}", robot.start_pos.first,
      //              robot.start_pos.second, robot.velocity.first,
      //              robot.velocity.second);

      auto predicted = robot.predict_position(x_size, y_size, seconds);
      // std::println("Predicted {},{}", predicted.first, predicted.second);

      // Upper left
      if (predicted.first < x_midpoint && predicted.second < y_midpoint)
        quadrants[0]++;
      // Upper right
      if (predicted.first > x_midpoint && predicted.second < y_midpoint)
        quadrants[1]++;
      // Lower left
      if (predicted.first < x_midpoint && predicted.second > y_midpoint)
        quadrants[2]++;
      // Lower right
      if (predicted.first > x_midpoint && predicted.second > y_midpoint)
        quadrants[3]++;

      robots.push_back(std::move(robot));
    }
  }

  christmas_tree_search(robots, x_size, y_size);

  return quadrants[0] * quadrants[1] * quadrants[2] * quadrants[3];
}

auto main(int argc, char *argv[]) -> int {
  auto filename = argv[1];
  auto input = std::ifstream(filename);

  if (!input.is_open())
    return 1;

  auto lines = std::vector<std::string>();
  auto line = std::string();

  while (input) {
    std::getline(input, line);
    lines.push_back(line);
  }

  auto result = safety_factor(lines, 101, 103, 100);
  std::println("Result one: {}", result);

  return 0;
}
