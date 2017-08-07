#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int tankVol(int h, int d, int vt) {
    double height = h;
    double radius = d/2.0;
    double velocity = vt;

    double sector_angle = 2.0 * acos((1.0-(height/radius)));
    double segment_area = (radius*radius * (sector_angle - sin(sector_angle)))/2.0;
    double cylinder_length = velocity / (radius*radius * M_PI);

    return floor(segment_area * cylinder_length);
}

void dotest(int h, int d, int vt, int expr) {
    int act = tankVol(h, d, vt);
    if(act != expr)
        printf("Error. Expected %d but got %d\n", expr, act);
    assert(act == expr);
}

int main() {
    dotest(5, 7, 3848, 2940);
    dotest(2, 7, 3848, 907);
    dotest(3, 6, 3500, 1750);
    dotest(3, 6, 3501, 1750);
}

