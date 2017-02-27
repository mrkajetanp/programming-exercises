#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

class Kata {
public:
    static std::vector<int> foldArray(std::vector<int> array, int runs);
};

std::vector<int> Kata::foldArray (std::vector<int> array, int runs) {
    std::vector<int> res;

    for (int i = 0, j = array.size()-1 ; i < std::floor(array.size()/2) ; ++i, --j)
        res.push_back(array[i] + array[j]);

    if (array.size()%2 != 0)
        res.push_back(array[std::ceil(array.size()/2)]);

    return (runs == 1) ? res : Kata::foldArray(res, runs-1);
}

void tests () {
    Kata kata;
    std::vector<int> expected = { 6, 6, 3 };
    std::vector<int> actual = kata.foldArray({ 1, 2, 3, 4, 5 }, 1);
    assert (actual == expected);

    expected = { 9, 6 };
    actual = kata.foldArray({ 1, 2, 3, 4, 5 }, 2);
    assert (actual == expected);

    expected = { 15 };
    actual = kata.foldArray({ 1, 2, 3, 4, 5 }, 3);
    assert (actual == expected);

    expected = { 14, 75, 0 };
    actual = kata.foldArray({ -9, 9, -8, 8, 66, 23 }, 1);
    assert (actual == expected);
}

int main () {
    tests ();
    return 0;
}

/*
  Different solution
  std::vector<int> foldArray(std::vector<int> a, int runs)
  {
  for (; runs > 0; --runs)
  {
  const auto half = a.size() / 2;
  std::transform(std::cbegin(a), std::cbegin(a) + half, std::crbegin(a), std::begin(a), std::plus<int>());
  a.resize((a.size() + 1) / 2);
  }
  return a;
    }
*/
