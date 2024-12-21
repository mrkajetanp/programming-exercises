#include <array>
#include <climits>
#include <cmath>
#include <format>
#include <fstream>
#include <print>
#include <ranges>
#include <regex>
#include <set>
#include <string>
#include <vector>

enum class Direction { Up, Down, Left, Right };

auto clear_input_buffer() {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF)
    ;
}

auto parse_move(char c) -> Direction {
  if (c == '^')
    return Direction::Up;
  if (c == 'v')
    return Direction::Down;
  if (c == '<')
    return Direction::Left;
  if (c == '>')
    return Direction::Right;

  throw "this should not happen";
};

using Coord = std::pair<int, int>;

class BigWarehouse;

class Warehouse {
public:
  std::vector<std::string> map;
  Coord robot;
  std::string commands;

  Warehouse(std::vector<std::string> map, std::string commands)
      : map(map), commands(commands) {
    for (auto i = 0; i < map.size(); ++i) {
      auto idx = map[i].find('@');
      if (idx != std::string::npos) {
        this->robot = std::make_pair(i, idx);
        this->map[i][idx] = '.';
        return;
      }
    }
  }

  auto move_box(int row, int col, Direction direction) -> bool {
    if (direction == Direction::Up) {
      if (row > 1) {
        if (this->map[row - 1][col] == 'O')
          if (!this->move_box(row - 1, col, direction))
            return false;
        if (this->map[row - 1][col] == '.') {
          map[row - 1][col] = 'O';
          map[row][col] = '.';
          return true;
        }
      }
    } else if (direction == Direction::Down) {
      if (row < map.size() - 1) {
        if (this->map[row + 1][col] == 'O')
          if (!this->move_box(row + 1, col, direction))
            return false;
        if (this->map[row + 1][col] == '.') {
          map[row + 1][col] = 'O';
          map[row][col] = '.';
          return true;
        }
      }
    } else if (direction == Direction::Left) {
      if (col > 1) {
        if (this->map[row][col - 1] == 'O')
          if (!this->move_box(row, col - 1, direction))
            return false;
        if (this->map[row][col - 1] == '.') {
          map[row][col - 1] = 'O';
          map[row][col] = '.';
          return true;
        }
      }
    } else if (direction == Direction::Right) {
      if (col < map[0].size() - 1) {
        if (this->map[row][col + 1] == 'O')
          if (!this->move_box(row, col + 1, direction))
            return false;
        if (this->map[row][col + 1] == '.') {
          map[row][col + 1] = 'O';
          map[row][col] = '.';
          return true;
        }
      }
    }
    return false;
  }

  auto move_robot(Direction direction) -> bool {
    int move_row;
    int move_col;

    switch (direction) {
    case Direction::Up:
      move_row = this->robot.first - 1;
      move_col = this->robot.second;
      break;
    case Direction::Down:
      move_row = this->robot.first + 1;
      move_col = this->robot.second;
      break;
    case Direction::Left:
      move_row = this->robot.first;
      move_col = this->robot.second - 1;
      break;
    case Direction::Right:
      move_row = this->robot.first;
      move_col = this->robot.second + 1;
      break;
    }

    if (map[move_row][move_col] == '.') {
      this->robot = std::make_pair(move_row, move_col);
      return true;
    }
    if (map[move_row][move_col] == 'O') {
      auto box_moved = this->move_box(move_row, move_col, direction);
      if (box_moved) {
        this->robot = std::make_pair(move_row, move_col);
        return true;
      }
    }
    return false;
  }

  auto simulate() {
    for (auto c : this->commands)
      this->move_robot(parse_move(c));
    map[this->robot.first][this->robot.second] = '@';
  }

  auto sum_box_coords() -> int {
    auto result = 0;

    for (const auto &[row_idx, row] : std::views::enumerate(this->map))
      for (const auto &[col_idx, elem] : std::views::enumerate(row))
        if (elem == 'O')
          result += row_idx * 100 + col_idx;

    return result;
  }

  auto print_map() -> void {
    for (auto &line : this->map)
      std::println("{}", line);
  }

  auto expand() -> BigWarehouse;
};

class BigWarehouse : public Warehouse {
public:
  BigWarehouse(std::vector<std::string> map, std::string commands)
      : Warehouse(std::move(map), std::move(commands)) {
    for (auto i = 0; i < map.size(); ++i) {
      auto idx = map[i].find('@');
      if (idx != std::string::npos) {
        this->robot = std::make_pair(i, idx);
        this->map[i][idx] = '.';
        return;
      }
    }
  }

  auto can_move_box(int row, int left, int right, Direction direction) -> bool {
    if (direction == Direction::Up) {
      // Free space
      if (this->map[row - 1][left] == '.' && this->map[row - 1][right] == '.')
        return true;

      // The easy case
      if (this->map[row - 1][left] == '[' && this->map[row - 1][right] == ']')
        return can_move_box(row - 1, left, right, direction);

      // The bad case
      if (this->map[row - 1][left] == ']' && this->map[row - 1][right] == '[')
        return can_move_box(row - 1, left - 1, left, direction) &&
               can_move_box(row - 1, right, right + 1, direction);

      // Right edge
      if (this->map[row - 1][left] == '.' && this->map[row - 1][right] == '[')
        return can_move_box(row - 1, right, right + 1, direction);

      // Left edge
      if (this->map[row - 1][left] == ']' && this->map[row - 1][right] == '.')
        return can_move_box(row - 1, left - 1, left, direction);
    }
    if (direction == Direction::Down) {
      // Free space
      if (this->map[row + 1][left] == '.' && this->map[row + 1][right] == '.')
        return true;

      // The easy case
      if (this->map[row + 1][left] == '[' && this->map[row + 1][right] == ']')
        return can_move_box(row + 1, left, right, direction);

      // The bad case
      if (this->map[row + 1][left] == ']' && this->map[row + 1][right] == '[')
        return can_move_box(row + 1, left - 1, left, direction) &&
               can_move_box(row + 1, right, right + 1, direction);

      // Right edge
      if (this->map[row + 1][left] == '.' && this->map[row + 1][right] == '[')
        return can_move_box(row + 1, right, right + 1, direction);

      // Left edge
      if (this->map[row + 1][left] == ']' && this->map[row + 1][right] == '.')
        return can_move_box(row + 1, left - 1, left, direction);
    }
    if (direction == Direction::Left) {
      // Free space
      if (this->map[row][left - 1] == '.')
        return true;

      if (this->map[row][left - 2] == '[' && this->map[row][left - 1] == ']')
        return can_move_box(row, left - 2, left - 1, direction);
    }

    if (direction == Direction::Right) {
      // Free space
      if (this->map[row][right + 1] == '.')
        return true;

      if (this->map[row][right + 1] == '[' && this->map[row][right + 2] == ']')
        return can_move_box(row, right + 1, right + 2, direction);
    }
    return false;
  }

  auto move_box(int row, int left, int right, Direction direction) -> bool {
    if (!this->can_move_box(row, left, right, direction))
      std::println("WARNING: CANNOT MOVE BOX");

    if (direction == Direction::Up) {
      // The easy case
      if (this->map[row - 1][left] == '[' && this->map[row - 1][right] == ']') {
        if (!can_move_box(row - 1, left, right, direction))
          return false;
        move_box(row - 1, left, right, direction);
      }

      // The bad case
      if (this->map[row - 1][left] == ']' && this->map[row - 1][right] == '[') {
        if (!can_move_box(row - 1, left - 1, left, direction) ||
            !can_move_box(row - 1, right, right + 1, direction))
          return false;
        move_box(row - 1, left - 1, left, direction);
        move_box(row - 1, right, right + 1, direction);
      }

      // Right edge
      if (this->map[row - 1][left] == '.' && this->map[row - 1][right] == '[') {
        if (!can_move_box(row - 1, right, right + 1, direction))
          return false;
        move_box(row - 1, right, right + 1, direction);
      }

      // Left edge
      if (this->map[row - 1][left] == ']' && this->map[row - 1][right] == '.') {
        if (!can_move_box(row - 1, left - 1, left, direction))
          return false;
        move_box(row - 1, left - 1, left, direction);
      }

      // Free space
      if (this->map[row - 1][left] == '.' && this->map[row - 1][right] == '.') {
        map[row - 1][left] = '[';
        map[row - 1][right] = ']';
        map[row][left] = '.';
        map[row][right] = '.';
        return true;
      }
    }

    if (direction == Direction::Down) {
      // The easy case
      if (this->map[row + 1][left] == '[' && this->map[row + 1][right] == ']') {
        if (!can_move_box(row + 1, left, right, direction))
          return false;
        move_box(row + 1, left, right, direction);
      }

      // The bad case
      if (this->map[row + 1][left] == ']' && this->map[row + 1][right] == '[') {
        if (!can_move_box(row + 1, left - 1, left, direction) ||
            !can_move_box(row + 1, right, right + 1, direction))
          return false;
        move_box(row + 1, left - 1, left, direction);
        move_box(row + 1, right, right + 1, direction);
      }

      // Right edge
      if (this->map[row + 1][left] == '.' && this->map[row + 1][right] == '[') {
        if (!can_move_box(row + 1, right, right + 1, direction))
          return false;
        move_box(row + 1, right, right + 1, direction);
      }

      // Left edge
      if (this->map[row + 1][left] == ']' && this->map[row + 1][right] == '.') {
        if (!can_move_box(row + 1, left - 1, left, direction))
          return false;
        move_box(row + 1, left - 1, left, direction);
      }

      // Free space
      if (this->map[row + 1][left] == '.' && this->map[row + 1][right] == '.') {
        map[row + 1][left] = '[';
        map[row + 1][right] = ']';
        map[row][left] = '.';
        map[row][right] = '.';
        return true;
      }
    }

    if (direction == Direction::Left) {
      if (this->map[row][left - 2] == '[' && this->map[row][left - 1] == ']') {
        if (!can_move_box(row, left - 2, left - 1, direction))
          return false;
        move_box(row, left - 2, left - 1, direction);
      }

      // Free space
      if (this->map[row][left - 1] == '.') {
        map[row][left - 1] = '[';
        map[row][left] = ']';
        map[row][right] = '.';
        return true;
      }
    }

    if (direction == Direction::Right) {
      if (this->map[row][right + 1] == '[' &&
          this->map[row][right + 2] == ']') {
        if (!can_move_box(row, right + 1, right + 2, direction))
          return false;
        move_box(row, right + 1, right + 2, direction);
      }

      // Free space
      if (this->map[row][right + 1] == '.') {
        map[row][right + 1] = ']';
        map[row][right] = '[';
        map[row][left] = '.';
        return true;
      }
    }

    return false;
  }

  auto move_robot(Direction direction) -> bool {
    int move_row;
    int move_col;

    switch (direction) {
    case Direction::Up:
      move_row = this->robot.first - 1;
      move_col = this->robot.second;
      break;
    case Direction::Down:
      move_row = this->robot.first + 1;
      move_col = this->robot.second;
      break;
    case Direction::Left:
      move_row = this->robot.first;
      move_col = this->robot.second - 1;
      break;
    case Direction::Right:
      move_row = this->robot.first;
      move_col = this->robot.second + 1;
      break;
    }

    if (move_row < 0 || move_row >= map.size() || move_col < 0 ||
        move_col >= map[move_row].size())
      return false;

    if (map[move_row][move_col] == '.') {
      this->robot = std::make_pair(move_row, move_col);
      return true;
    }

    if (map[move_row][move_col] == '#')
      return false;

    if (map[move_row][move_col] == '[' && map[move_row][move_col + 1] == ']') {
      auto can_move =
          this->can_move_box(move_row, move_col, move_col + 1, direction);
      if (can_move) {
        this->move_box(move_row, move_col, move_col + 1, direction);
        this->robot = std::make_pair(move_row, move_col);
        return true;
      }
    }

    if (map[move_row][move_col - 1] == '[' && map[move_row][move_col] == ']') {
      auto can_move =
          this->can_move_box(move_row, move_col - 1, move_col, direction);
      if (can_move) {
        this->move_box(move_row, move_col - 1, move_col, direction);
        this->robot = std::make_pair(move_row, move_col);
        return true;
      }
    }

    return false;
  }

  auto simulate() {
    for (auto c : this->commands) {
      auto direction = parse_move(c);
      // std::println("Move: {}", c);
      // std::getchar();
      this->move_robot(direction);
      // map[this->robot.first][this->robot.second] = '@';
      // this->print_map();
      // map[this->robot.first][this->robot.second] = '.';
    }

    map[this->robot.first][this->robot.second] = '@';
  }

  auto interactive() {
    char c;
    while (true) {
      map[this->robot.first][this->robot.second] = '@';
      this->print_map();
      map[this->robot.first][this->robot.second] = '.';
      c = getchar();
      clear_input_buffer();
      if (c == 'k')
        this->move_robot(Direction::Up);
      if (c == 'j')
        this->move_robot(Direction::Down);
      if (c == 'h')
        this->move_robot(Direction::Left);
      if (c == 'l')
        this->move_robot(Direction::Right);
    }
  }

  auto sum_box_coords() -> int {
    auto result = 0;

    for (const auto &[row_idx, row] : std::views::enumerate(this->map))
      for (const auto &[col_idx, elem] : std::views::enumerate(row))
        if (elem == '[')
          result += (100 * row_idx + col_idx);

    return result;
  }
};

auto Warehouse::expand() -> BigWarehouse {
  auto new_map = std::vector<std::string>();

  map[this->robot.first][this->robot.second] = '@';

  for (const auto &[row_idx, row] : std::views::enumerate(this->map)) {
    auto ss = std::stringstream();
    for (const auto &[col_idx, elem] : std::views::enumerate(row)) {
      if (elem == '#')
        ss << "##";
      if (elem == '.')
        ss << "..";
      if (elem == 'O')
        ss << "[]";
      if (elem == '@')
        ss << "@.";
    }
    new_map.push_back(ss.str());
  }

  map[this->robot.first][this->robot.second] = '.';

  return std::move(
      BigWarehouse(std::move(new_map), std::move(std::string(this->commands))));
}

auto main(int argc, char *argv[]) -> int {
  auto filename = argv[1];
  auto input = std::ifstream(filename);

  if (!input.is_open())
    return 1;

  auto map_lines = std::vector<std::string>();
  auto line = std::string();

  while (input) {
    std::getline(input, line);
    if (line.empty())
      break;
    map_lines.push_back(line);
  }

  auto commands = std::string();

  while (input) {
    std::getline(input, line);
    commands.append(line);
  }

  auto warehouse = Warehouse(std::move(map_lines), std::move(commands));
  // warehouse.print_map();
  auto big_warehouse = warehouse.expand();
  // big_warehouse.interactive();
  big_warehouse.print_map();
  big_warehouse.simulate();
  big_warehouse.print_map();
  warehouse.simulate();
  std::println("Result one: {}", warehouse.sum_box_coords());
  std::println("Result two: {}", big_warehouse.sum_box_coords());

  // auto result = safety_factor(lines, 101, 103, 100);
  // std::println("Result one: {}", result);

  return 0;
}
