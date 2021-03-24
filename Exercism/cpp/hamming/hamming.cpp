#include "hamming.h"

using std::size_t;
using std::string;

namespace hamming {

int compute(string a, string b)
{
    if (a.length() != b.length())
        throw std::domain_error("string lengths don't match");

    int count = 0;

    for (size_t i = 0; i < a.length(); ++i) {
        if (a[i] != b[i])
            count++;
    }

    return count;
}

} // namespace hamming
