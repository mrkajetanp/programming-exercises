#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

class BestTravel {
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls);
};

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls) {
    size_t n = ls.size();
    if (static_cast<size_t>(k) > n)
        return -1;

    int max = -1;

    std::string bitmask(k, 1);
    bitmask.resize(n, 0); 

    do {
        int sum = 0;
        for (size_t i = 0 ; i < n ; ++i)
            if (bitmask[i])
                sum += ls[i];
        if ((sum >= max) && (sum <= t))
            max = sum;
    } while(std::prev_permutation(bitmask.begin(), bitmask.end()));

    return max;
}

void tests() {
    std::vector<int> ts = {50, 55, 56, 57, 58};
    int n = BestTravel::chooseBestSum(163, 3, ts);
    assert(n == 163);
}

int main() {
    tests();
    return 0;
}
