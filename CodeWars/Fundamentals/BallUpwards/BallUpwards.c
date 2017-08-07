#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int maxBall(int v0) {
    return round(((double)v0/3.6/0.981));
}

void testequal(int v0, int exp) {
    int act = maxBall(v0);
    if(act != exp)
        printf("Error. Expected %d but got %d\n", exp, act);
    assert(exp == act);
}

int main() {
    {
        testequal(37, 10);
        testequal(45, 13);
        testequal(99, 28);
        testequal(85, 24);
    }
}


