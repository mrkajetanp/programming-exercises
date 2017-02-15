#include <iostream>
#include <vector>
#include <assert.h>

int sequence (int n) {
    std::vector<int> seq { 0, 1, 1, 2, 0, 2, 2, 1 };
    return seq[(n-1)%8];
}

int main () {
    assert (sequence(1) == 0);
    assert (sequence(2) == 1);
    assert (sequence(3) == 1);
    assert (sequence(4) == 2);
    assert (sequence(5) == 0);

    return 0;
}
