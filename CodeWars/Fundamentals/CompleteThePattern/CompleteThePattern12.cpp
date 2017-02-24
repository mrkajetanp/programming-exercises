#include <iostream>
#include <string>
#include <cassert>

std::string pattern (int n) {
    if (n < 1)
        return "";

    std::string res = "";
    std::string temp (2*n-1, ' ');

    for (int i = 0 ; i < n ; ++i) {
        temp[i] = '0'+((i+1)%10);
        temp[2*n-2-i] = '0'+((i+1)%10);
        res += temp;
        res += '\n';
        temp = std::string (2*n-1, ' ');
    }
    for (int i = n-2 ; i >= 0 ; --i) {
        temp[i] = '0'+((i+1)%10);
        temp[2*n-2-i] = '0'+((i+1)%10);
        res += temp;
        res += '\n';
        temp = std::string (2*n-1, ' ');
    }
    res.pop_back ();

    return res;
}

void tests () {
    std::string expected = "\n"
        "1   1\n"
        " 2 2 \n"
        "  3  \n"
        " 2 2 \n"
        "1   1";
    std::string actual = "\n" + pattern(3);
    assert (expected == actual);

    expected = "\n"
        "1       1\n"
        " 2     2 \n"
        "  3   3  \n"
        "   4 4   \n"
        "    5    \n"
        "   4 4   \n"
        "  3   3  \n"
        " 2     2 \n"
        "1       1";
    actual = "\n" + pattern(5);
    assert (expected == actual);
}

int main () {
    tests ();

    return 0;
}







