#include <iostream>
#include <vector>
#include <cassert>

class DirReduction {
public:
    static std::vector<std::string> dirReduc (std::vector<std::string> &arr);
};

std::vector<std::string> DirReduction::dirReduc (std::vector<std::string> &arr) {
    std::vector<std::string> dirs = arr;

    auto i = dirs.begin ();
    while (i != dirs.end()) {
        if (dirs.size() == 1)
            break;
        if ((*i == "NORTH" && *(i+1) == "SOUTH") ||
            (*i == "SOUTH" && *(i+1) == "NORTH") ||
            (*i == "WEST" && *(i+1) == "EAST") ||
            (*i == "EAST" && *(i+1) == "WEST")) {
            dirs.erase (i, i+2);
            i = dirs.begin();
            continue;
        }
        i++;
    }
    return dirs;
}


void test () {
    std::vector<std::string> d1 =
        {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    std::vector<std::string> sol1 = {"WEST"};
    assert (DirReduction::dirReduc(d1) == sol1);

    std::vector<std::string> d2 =
        {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "SOUTH"};
    std::vector<std::string> sol2 = {"SOUTH"};
    assert (DirReduction::dirReduc(d2) == sol2);
}

int main () {
    test ();
    return 0;
}
