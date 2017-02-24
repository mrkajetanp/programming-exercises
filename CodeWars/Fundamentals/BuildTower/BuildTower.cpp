#include <iostream>
#include <vector>
#include <cassert>

class Kata {
public:
    static std::vector<std::string> towerBuilder (int nFloors);
};

std::vector<std::string> Kata::towerBuilder (int nFloors) {
    std::vector<std::string> res;

    for (int i = 0 ; i < nFloors ; ++i)
        res.push_back (std::string (nFloors-i-1, ' ') +
                       std::string (i*2+1, '*') +
                       std::string (nFloors-i-1, ' '));
    return res;
}

void tests () {
    Kata kata;
    std::vector<std::string> expected = { "*" };
    assert (kata.towerBuilder(1) == expected);

    expected = { " * ", "***" };
    assert (kata.towerBuilder(2) == expected);

    expected = { "  *  ", " *** ", "*****" };
    assert (kata.towerBuilder(3) == expected);
}

int main () {
    tests ();
    return 0;
}

