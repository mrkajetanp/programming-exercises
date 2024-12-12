#include <algorithm>
#include <cmath>
#include <format>
#include <fstream>
#include <print>
#include <set>
#include <string>
#include <vector>

using Coord = std::pair<int, int>;

auto explore_region(std::vector<std::string> &map, Coord pos,
                    std::set<Coord> &region) -> void {
  auto curr = map[pos.first][pos.second];
  if (region.contains(pos))
    return;
  region.insert(pos);
  // Explore upwards
  if (pos.first > 0 && map[pos.first - 1][pos.second] == curr)
    explore_region(map, std::make_pair(pos.first - 1, pos.second), region);
  // Explore downwards
  if (pos.first < map.size() - 1 && map[pos.first + 1][pos.second] == curr)
    explore_region(map, std::make_pair(pos.first + 1, pos.second), region);
  // Explore leftwards
  if (pos.second > 0 && map[pos.first][pos.second - 1] == curr)
    explore_region(map, std::make_pair(pos.first, pos.second - 1), region);
  // Explore rightwards
  if (pos.second < map[0].size() - 1 && map[pos.first][pos.second + 1] == curr)
    explore_region(map, std::make_pair(pos.first, pos.second + 1), region);
}

auto find_region(std::vector<std::string> &map, Coord pos) -> std::set<Coord> {
  auto region = std::set<Coord>();
  explore_region(map, pos, region);
  return std::move(region);
}

auto perimeter(std::set<Coord> &region) -> int {
  auto result = 0;
  for (auto &plot : region) {
    auto up = std::make_pair(plot.first - 1, plot.second);
    if (!region.contains(up))
      result++;
    auto down = std::make_pair(plot.first + 1, plot.second);
    if (!region.contains(down))
      result++;
    auto left = std::make_pair(plot.first, plot.second - 1);
    if (!region.contains(left))
      result++;
    auto right = std::make_pair(plot.first, plot.second + 1);
    if (!region.contains(right))
      result++;
  }
  return result;
}

enum class Direction { Up, Down, Right, Left };

std::string direction_to_string(Direction direction) {
  switch (direction) {
  case Direction::Up:
    return "Up";
  case Direction::Down:
    return "Down";
  case Direction::Left:
    return "Left";
  case Direction::Right:
    return "Right";
  }
}

class Edge {
public:
  Coord pos;
  Direction direction;
  Edge(int row, int col, Direction direction)
      : pos(std::make_pair(row, col)), direction(direction) {}
  Edge(Coord pos, Direction direction) : pos(pos), direction(direction) {}

  bool operator<(const Edge &other) const {
    return direction == other.direction && pos < other.pos;
  }

  bool operator=(const Edge &other) const {
    return direction == other.direction && pos == other.pos;
  }

  std::string to_string() const {
    return std::format("({},{},{})", pos.first, pos.second,
                       direction_to_string(direction));
  }

  int row() { return this->pos.first; }
  int col() { return this->pos.second; }
};

void try_direction(std::set<Coord> &region, std::vector<std::set<Edge>> &sides,
                   Coord plot, Direction direction) {
  Coord edge_coord;
  switch (direction) {
  case Direction::Up:
    edge_coord = std::make_pair(plot.first - 1, plot.second);
    break;
  case Direction::Down:
    edge_coord = std::make_pair(plot.first + 1, plot.second);
    break;
  case Direction::Left:
    edge_coord = std::make_pair(plot.first, plot.second - 1);
    break;
  case Direction::Right:
    edge_coord = std::make_pair(plot.first, plot.second + 1);
    break;
  }

  if (!region.contains(edge_coord)) {
    auto edge = Edge(plot, direction);

    auto vertical = direction == Direction::Up || direction == Direction::Down;
    auto candidate_one = (vertical)
                             ? Edge(edge.row(), edge.col() - 1, direction)
                             : Edge(edge.row() + 1, edge.col(), direction);
    auto candidate_two = (vertical)
                             ? Edge(edge.row(), edge.col() + 1, direction)
                             : Edge(edge.row() - 1, edge.col(), direction);

    auto found = false;
    auto seen = false;
    for (auto &side : sides) {
      if (side.contains(edge))
        seen = true;
      if (!side.contains(candidate_one) && !side.contains(candidate_two))
        continue;

      side.insert(edge);
      found = true;
      break;
    }
    if (!found && !seen) {
      sides.push_back(std::set<Edge>({edge}));
    }
  }
}

auto count_sides(std::set<Coord> &region) -> int {
  auto sides_up = std::vector<std::set<Edge>>();
  auto sides_down = std::vector<std::set<Edge>>();
  auto sides_left = std::vector<std::set<Edge>>();
  auto sides_right = std::vector<std::set<Edge>>();

  for (auto &plot : region) {
    try_direction(region, sides_up, plot, Direction::Up);
    try_direction(region, sides_down, plot, Direction::Down);
    try_direction(region, sides_left, plot, Direction::Left);
    try_direction(region, sides_right, plot, Direction::Right);
  }

  return sides_up.size() + sides_down.size() + sides_left.size() +
         sides_right.size();
}

auto fence_price(std::vector<std::string> &map) -> std::pair<long, long> {
  auto price = static_cast<long>(0);
  auto price_sides = static_cast<long>(0);

  auto regions = std::vector<std::set<Coord>>();
  for (auto row = 0; row < map.size(); ++row) {
    for (auto col = 0; col < map[0].size(); ++col) {
      auto curr = std::make_pair(row, col);
      auto regionsContain = [&curr](auto &region) {
        return region.contains(curr);
      };
      // TODO: could be optimised further
      if (std::any_of(regions.begin(), regions.end(), regionsContain))
        continue;
      regions.push_back(find_region(map, curr));
    }
  }

  for (auto &region : regions) {
    price += region.size() * perimeter(region);
    auto sides = count_sides(region);
    price_sides += region.size() * sides;
  }

  return std::make_pair(price, price_sides);
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
    if (line.empty())
      break;
    lines.push_back(line);
  }

  auto result = fence_price(lines);
  std::println("Result one: {}", result.first);
  std::println("Result two: {}", result.second);

  return 0;
}
