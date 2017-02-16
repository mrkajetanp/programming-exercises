#include "bob.h"

bool isAllUpper (const std::string& s) {
    for (auto& c : s)
        if (isalpha(c))
            if (!isupper(c))
                return false;
    return true;
}

bool isAllNumbers (const std::string& s) {
    for (auto& c : s)
        if (isalnum(c))
            if (!isdigit(c))
                return false;
    return true;
}

std::string trim (const std::string& str) {
    const auto strBegin = str.find_first_not_of(" \t");
    if (strBegin == std::string::npos)
        return "";

    const auto strEnd = str.find_last_not_of (" \t");
    const auto strRange = strEnd - strBegin + 1;

    return str.substr (strBegin, strRange);
}

std::string bob::hey (std::string s) {
    s = trim (s);
    if (s == "")
        return "Fine. Be that way!";
    if (isAllNumbers(s)) {
        if (s.back() == '?')
            return "Sure.";
        else
            return "Whatever.";
    }

    if (isAllUpper(s))
        return "Whoa, chill out!";
    if (s.back() == '?')
        return "Sure.";

    return "Whatever.";
}
