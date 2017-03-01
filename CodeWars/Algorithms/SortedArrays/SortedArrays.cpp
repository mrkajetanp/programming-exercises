#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int nthSmallest (std::vector<std::vector<int>> vec, int n) {
    std::vector<int> res;
    for (auto& v : vec)
        for (auto x : v)
            res.push_back(x);

    std::sort(res.begin(), res.end());
    return res[n-1];
}

void tests () {
    int actual = nthSmallest({ { 1, 5 }, { 2 }, { 4, 8, 9 } }, 4);
    assert (actual == 5);
}

int main () {
    tests ();
    return 0;
}
