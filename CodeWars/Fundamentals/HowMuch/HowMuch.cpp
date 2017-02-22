#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <cassert>

class Carboat {
public:
    static std::string howmuch (int m, int n);
};

std::string Carboat::howmuch (int m, int n) {
    if (m > n)    std::swap (m, n);
    std::vector<std::string> results;
    std::stringstream ss;
    auto c = 0.0;
    auto b = 0.0;

    for (int i = m; i <= n; i++) {
        c = (i-1)/9.0;
        b = (i-2)/7.0;
        if (c < 0 || b < 0)    continue;
        double intpart;
        if (std::modf (c, &intpart) == 0 && std::modf (b, &intpart) == 0) {
            ss << '[' << "M: " << i << " B: " << b << " C: " << c << ']';
            results.push_back (ss.str());
            ss.str ("");
            ss.clear ();
        }
    }

    ss << '[';
    for (auto& s : results)
        ss << s;
    ss << ']';

    return ss.str();
}

void tests () {
    assert (Carboat::howmuch (1,100) == "[[M: 37 B: 5 C: 4][M: 100 B: 14 C: 11]]");
    assert (Carboat::howmuch (2950, 2950) == "[]");
    assert (Carboat::howmuch (20000, 20100) ==
            "[[M: 20008 B: 2858 C: 2223][M: 20071 B: 2867 C: 2230]]");
}

int main () {
    tests ();

    return 0;
}
