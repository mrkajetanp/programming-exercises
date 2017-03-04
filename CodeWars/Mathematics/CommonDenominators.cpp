#include <iostream>
#include <vector>
#include <cassert>

class Fracts {
public:
    static std::string convertFrac(const std::vector<std::vector<unsigned long long>> &lst);
    static unsigned long long lcm(unsigned long long a, unsigned long long b);
    static unsigned long long gcd(unsigned long long a, unsigned long long b);
    static unsigned long long vecLcm(const std::vector<std::vector<unsigned long long>>& vec);
};

unsigned long long Fracts::gcd(unsigned long long a, unsigned long long b) {
    return b == 0 ? a : gcd(b,a%b);
}

unsigned long long Fracts::lcm(unsigned long long a, unsigned long long b) {
    return (a*b) / gcd(a,b);
}

unsigned long long Fracts::vecLcm(const std::vector<std::vector<unsigned long long>>& vec) {
    unsigned long long curr = vec[0][1];
    for (size_t i = 1 ; i < vec.size() ; ++i)
        curr = lcm(curr, vec[i][1]);
    return curr;
}


std::string Fracts::convertFrac(const std::vector<std::vector<unsigned long long>>& lst) {
    std::string res = "";
    unsigned long long den = vecLcm(lst);
    for (auto& v : lst)
        res.append("(" + std::to_string(v[0]*(den/v[1])) + "," + std::to_string(den) + ")");
    return res;
}

void testGcd() {
    assert(Fracts::gcd(3,5) == 1);
    assert(Fracts::gcd(12,60) == 12);
    assert(Fracts::gcd(12,90) == 6);
}

void testLcm() {
    assert(Fracts::lcm(3,5) == 15);
    assert(Fracts::lcm(6,15) == 30);
    assert(Fracts::lcm(4,8) == 8);
}

void testVecLcm() {
    std::vector<std::vector<unsigned long long>> a1 = { {1,2}, {1,3}, {1,4} };
    assert (Fracts::vecLcm(a1) == 12);
}

void testConvertFrac() {
    std::vector<std::vector<unsigned long long>> a1 = { {1,2}, {1,3}, {1,4} };
    std::cout << Fracts::convertFrac(a1) << std::endl;
}

int main() {
    testGcd();
    testLcm();
    testConvertFrac();
    return 0;
}
