#include "isogram.h"

#include <vector>

using std::string;
using std::vector;

namespace isogram {

bool is_isogram(string input)
{
    vector<bool> letters(26, false);

    for (string::size_type i = 0; i < input.length(); ++i) {
        if (!std::isalpha(input[i]))
            continue;

        if (letters[std::tolower(input[i]) - 97])
            return false;

        letters[std::tolower(input[i]) - 97] = true;
    }

    return true;
}

} // namespace isogram
