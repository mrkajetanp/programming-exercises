#include <assert.h>

class Bouncingball {
public:
    static int bouncingBall (double h, double bounce, double window);
};

int Bouncingball::bouncingBall (double h, double bounce, double window) {
    auto bounces = 1;
    if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h)
        return -1;

    while (h > window) {
        h *= bounce;
        if (h > window)
            bounces += 2;
    }


    return bounces;
    // return (int)floor(log(window / h) / log(bounce)) * 2 + 1;
    // Second possible way to solve this
}

int main () {
    assert (Bouncingball::bouncingBall(3, 0.66, 1.5) == 3);
    assert (Bouncingball::bouncingBall(30, 0.66, 1.5) == 15);

    return 0;
}
