#include <climits>
#include <cmath>
#include <fstream>
#include <print>
#include <regex>
#include <string>
#include <vector>

using u64 = unsigned long;
using Coord = std::pair<u64, u64>;

static const u64 A_PRICE = 3;
static const u64 B_PRICE = 1;

class SubMatrix {
public:
  const std::vector<std::vector<double>> *source;
  std::vector<double> replace_column;
  const SubMatrix *prev;
  size_t size;
  int column_idx;

  SubMatrix(const std::vector<std::vector<double>> &src,
            const std::vector<double> &rc)
      : source(&src), replace_column(rc), prev(nullptr), column_idx(-1) {
    size = replace_column.size();
  }

  SubMatrix(const SubMatrix &p) : source(nullptr), prev(&p), column_idx(-1) {
    this->size = p.size - 1;
  }

  SubMatrix(const SubMatrix &p, int deletedColumnIndex)
      : source(nullptr), prev(&p), column_idx(deletedColumnIndex) {
    this->size = p.size - 1;
  }

  double index(int row, int col) const {
    if (source != nullptr) {
      if (col == column_idx) {
        return replace_column[row];
      } else {
        return (*source)[row][col];
      }
    } else {
      if (col < column_idx) {
        return prev->index(row + 1, col);
      } else {
        return prev->index(row + 1, col + 1);
      }
    }
  }

  double determinant() const {
    if (size == 1) {
      return index(0, 0);
    }
    if (size == 2) {
      return index(0, 0) * index(1, 1) - index(0, 1) * index(1, 0);
    }
    SubMatrix m(*this);
    double det = 0.0;
    int sign = 1;
    for (size_t c = 0; c < size; ++c) {
      m.column_idx = c;
      double d = m.determinant();
      det += index(0, c) * d * sign;
      sign = -sign;
    }
    return det;
  }
};

std::vector<double> solve(SubMatrix &matrix) {
  double det = matrix.determinant();
  if (det == 0.0) {
    throw std::runtime_error("The determinant is zero.");
  }

  std::vector<double> answer(matrix.size);
  for (int i = 0; i < matrix.size; ++i) {
    matrix.column_idx = i;
    answer[i] = matrix.determinant() / det;
  }
  return answer;
}

std::vector<double>
solve_cramer(const std::vector<std::vector<double>> &equations) {
  int size = equations.size();
  if (std::any_of(equations.cbegin(), equations.cend(),
                  [size](const std::vector<double> &a) {
                    return a.size() != size + 1;
                  })) {
    throw std::runtime_error("Each equation must have the expected size.");
  }

  std::vector<std::vector<double>> matrix(size);
  std::vector<double> column(size);
  for (int r = 0; r < size; ++r) {
    column[r] = equations[r][size];
    matrix[r].resize(size);
    for (int c = 0; c < size; ++c) {
      matrix[r][c] = equations[r][c];
    }
  }

  SubMatrix sm(matrix, column);
  return solve(sm);
}

class Button {
public:
  u64 x_delta;
  u64 y_delta;

  Button(u64 x_delta, u64 y_delta) : x_delta(x_delta), y_delta(y_delta) {}

  auto to_string() const -> std::string {
    return std::format("X+{}, Y+{}", x_delta, y_delta);
  }
};

class Game {
public:
  Button A;
  Button B;
  Coord prize;

  Game(Button A, Button B, Coord prize) : A(A), B(B), prize(prize) {}

  auto to_string() const -> std::string {
    return std::format("{}\n{}\nX={}, Y={}", A.to_string(), B.to_string(),
                       prize.first, prize.second);
  }
};

auto count_tokens(Game &game) -> u64 {
  auto x_target = game.prize.first;
  auto y_target = game.prize.second;

  auto min_tokens = ULONG_MAX;

  auto max_a_presses =
      std::max(x_target / game.A.x_delta, y_target / game.A.y_delta);
  auto max_b_presses =
      std::max(x_target / game.B.x_delta, y_target / game.B.y_delta);

  for (auto a_press = 0; a_press < max_a_presses; ++a_press) {
    for (auto b_press = 0; b_press < max_b_presses; ++b_press) {
      auto curr_x = a_press * game.A.x_delta + b_press * game.B.x_delta;
      auto curr_y = a_press * game.A.y_delta + b_press * game.B.y_delta;
      if (curr_x != x_target || curr_y != y_target)
        continue;

      auto tokens = a_press * A_PRICE + b_press * B_PRICE;
      if (tokens < min_tokens)
        min_tokens = tokens;
    }
  }

  return (min_tokens == ULONG_MAX) ? 0 : min_tokens;
}

auto solve_game(Game &game) -> u64 {
  std::vector<std::vector<double>> equations = {
      {static_cast<double>(game.A.x_delta), static_cast<double>(game.B.x_delta),
       static_cast<double>(game.prize.first)},
      {static_cast<double>(game.A.y_delta), static_cast<double>(game.B.y_delta),
       static_cast<double>(game.prize.second)},
  };
  auto solution = solve_cramer(equations);
  auto a_presses = std::floor(solution[0]);
  auto b_presses = std::floor(solution[1]);
  if (a_presses * game.A.x_delta + b_presses * game.B.x_delta ==
          game.prize.first &&
      a_presses * game.A.y_delta + b_presses * game.B.y_delta ==
          game.prize.second)
    return a_presses * A_PRICE + b_presses * B_PRICE;
  else
    return 0;
}

auto fewest_tokens(std::vector<std::string> &lines) -> std::pair<u64, u64> {
  auto result = static_cast<u64>(0);
  auto result_two = static_cast<u64>(0);
  auto idx = 0;

  auto num_regex = std::regex("(\\d+)");
  while (idx < lines.size()) {
    auto line = lines[idx++];
    if (line.empty())
      break;
    auto start = std::sregex_iterator(line.begin(), line.end(), num_regex);
    auto end = std::sregex_iterator();
    auto A = Button(std::atol(start->str().c_str()),
                    std::atol((++start)->str().c_str()));
    line = lines[idx++];
    start = std::sregex_iterator(line.begin(), line.end(), num_regex);
    end = std::sregex_iterator();
    auto B = Button(std::atol(start->str().c_str()),
                    std::atol((++start)->str().c_str()));
    line = lines[idx++];
    start = std::sregex_iterator(line.begin(), line.end(), num_regex);
    end = std::sregex_iterator();
    auto prize = std::make_pair(std::atol(start->str().c_str()),
                                std::atol((++start)->str().c_str()));
    auto game = Game(std::move(A), std::move(B), std::move(prize));
    result += solve_game(game);
    game.prize.first += 10000000000000;
    game.prize.second += 10000000000000;
    result_two += solve_game(game);
    idx++;
  }

  return std::make_pair(result, result_two);
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

  auto result = fewest_tokens(lines);
  std::println("Result one: {}", result.first);
  std::println("Result two: {}", result.second);

  return 0;
}
