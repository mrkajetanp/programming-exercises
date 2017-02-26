#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

class SumFractions {
public:
    static std::pair<int,int> sumFracts(std::vector<std::vector<int>>& l);
    static int vecLcm (const std::vector<std::vector<int>>& vec);
    static int lcm (int a, int b);
    static int gcd (int a, int b);
};

std::pair<int,int> SumFractions::sumFracts (std::vector<std::vector<int>>& vec) {
    if (vec.empty())
        return std::make_pair (0, 1);

    std::vector<std::vector<int>> resv = vec;
    auto den = vecLcm (vec);
    auto nom = 0;
    for (auto& v : resv) {
        v[0] = v[0]*(den/v[1]);
        v[1] = den;
    }
    for (auto& v : resv)
        nom += v[0];
    auto div = gcd (nom, den);
    return std::make_pair (nom/div, den/div);
}

int SumFractions::gcd (int a, int b) {
    return b == 0 ? a : gcd (b, a % b);
}

int SumFractions::lcm (int a, int b) {
    return (a*b) / gcd(a,b);
}

int SumFractions::vecLcm (const std::vector<std::vector<int>>& vec) {
    int curr = vec[0][1];
    for (size_t i = 1 ; i < vec.size() ; ++i)
        curr = lcm (curr, vec[i][1]);
    return curr;
}

void tests () {
    std::vector<std::vector<int>> a1 = { {1,2}, {2,9}, {3,18}, {4,24}, {6,48} };
    std::pair<int, int> a1e = { 85, 72 };
    assert (SumFractions::sumFracts(a1) == a1e);

    std::vector<std::vector<int>> a2 = { {1, 2}, {1, 3}, {1, 4} };
    std::pair<int, int> a2e = { 13, 12 };
    assert (SumFractions::sumFracts(a2) == a2e);

    std::vector<std::vector<int>> a3 = { {1, 3}, {5, 3} };
    std::pair<int, int> a3e = { 2, 1 };
    assert (SumFractions::sumFracts(a3) == a3e);

    std::vector<std::vector<int>> a4 = { };
    std::pair<int, int> a4e = { 0, 1 };
    assert (SumFractions::sumFracts(a4) == a4e);
}

int main () {
    tests ();
    return 0;
}
