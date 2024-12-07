#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <print>
#include <regex>
#include <set>
#include <string>
#include <utility>
#include <vector>

enum class Direction { Up, Down, Left, Right, None };

auto get_direction(char c) -> Direction {
  switch (c) {
  case '^':
    return Direction::Up;
  case '>':
    return Direction::Right;
  case '<':
    return Direction::Left;
  case 'v':
    return Direction::Down;
  }
  return Direction::None;
}

auto process_map(std::vector<std::string> &map) -> int {
  auto visited = 0;
  auto row = -1;
  auto col = -1;

  for (auto i = 0; i < map.size(); ++i) {
    auto pos = map[i].find("^");
    if (pos != std::string::npos) {
      row = i;
      col = pos;
      break;
    }
  }

  auto direction = get_direction(map[row][col]);

  auto loop_map = std::vector<std::string>(map.begin(), map.end());

  while (row >= 0 && row < map.size() && col >= 0 && col < map[0].size()) {
    if (direction == Direction::Up) {
      if (map[row - 1][col] == '#') {
        direction = Direction::Right;
        loop_map[row][col] = '+';
      } else {
        if (map[row][col] != 'X') {
          visited++;
          map[row][col] = 'X';
          if (loop_map[row][col] != '+')
            loop_map[row][col] = '|';
        }
        row--;
      }
    }

    if (direction == Direction::Right) {
      if (map[row][col + 1] == '#') {
        direction = Direction::Down;
        loop_map[row][col] = '+';
      } else {
        if (map[row][col] != 'X') {
          visited++;
          map[row][col] = 'X';
          if (loop_map[row][col] != '+')
            loop_map[row][col] = '-';
        }
        col++;
      }
    }

    if (direction == Direction::Down) {
      if (map[row + 1][col] == '#') {
        direction = Direction::Left;
        loop_map[row][col] = '+';
      } else {
        if (map[row][col] != 'X') {
          visited++;
          map[row][col] = 'X';
          if (loop_map[row][col] != '+')
            loop_map[row][col] = '|';
        }
        row++;
      }
    }

    if (direction == Direction::Left) {
      if (map[row][col - 1] == '#') {
        direction = Direction::Up;
        loop_map[row][col] = '+';
      } else {
        if (map[row][col] != 'X') {
          visited++;
          map[row][col] = 'X';
          if (loop_map[row][col] != '+')
            loop_map[row][col] = '-';
        }
        col--;
      }
    }
  }

  for (auto &row : map)
    std::cout << row << '\n';

  std::cout << '\n';

  return visited;
}

auto simulate_obstacles(std::vector<std::string> &map) -> int {
  auto obstacles = 0;
  auto start_row = -1;
  auto start_col = -1;

  for (auto i = 0; i < map.size(); ++i) {
    auto pos = map[i].find("^");
    if (pos != std::string::npos) {
      start_row = i;
      start_col = pos;
      break;
    }
  }

  auto start_direction = get_direction(map[start_row][start_col]);

  auto row = start_row;
  auto col = start_col;
  auto direction = start_direction;

  auto history = std::map<std::pair<int, int>, Direction>();
  for (auto i = 0; i < map.size(); i++) {
    for (auto j = 0; j < map[0].size(); j++) {
      std::cout << "Starting " << i << ' ' << j << '\n';
      if (map[i][j] == '#' || map[i][j] == '^')
        continue;
      map[i][j] = '#';
      row = start_row;
      col = start_col;
      direction = start_direction;
      history.clear();

      while (row >= 0 && row < map.size() && col >= 0 && col < map[0].size()) {
        if (history.find({row, col}) != history.end()) {
          if (history[{row, col}] == direction) {
            obstacles++;
            break;
          }
        } else {
          history[{row, col}] = direction;
        }

        if (direction == Direction::Up) {
          if (map[row - 1][col] == '#') {
            direction = Direction::Right;
          } else {
            row--;
          }
        } else if (direction == Direction::Right) {
          if (map[row][col + 1] == '#') {
            direction = Direction::Down;
          } else {
            col++;
          }
        } else if (direction == Direction::Down) {
          if (map[row + 1][col] == '#') {
            direction = Direction::Left;
          } else {
            row++;
          }
        } else if (direction == Direction::Left) {
          if (map[row][col - 1] == '#') {
            direction = Direction::Up;
          } else {
            col--;
          }
        }
      }

      // for (auto &row : map)
      //   std::cout << row << '\n';
      // std::cout << '\n';

      map[i][j] = '.';
    }
  }

  // for (auto &row : map)
  //   std::cout << row << '\n';

  // std::cout << '\n';

  return obstacles;
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

  auto obstacles = simulate_obstacles(lines);
  auto result = process_map(lines);

  std::cout << "Result: " << result << '\n';
  std::cout << "Obstacles: " << obstacles << '\n';

  return 0;
}
