#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

double dist(double v, double mu) {
    double g = 9.81;
    double km_to_m = 1000.0 / 3600.0;

    double braking_distance = pow((v*km_to_m), 2) / (2.0*mu*g);
    double reaction_distance = v*km_to_m;

    return braking_distance + reaction_distance;
}

double speed(double d, double mu) {
    double g = 9.81;
    double m_to_km = 3600.0 / 1000.0;

    return (mu*g/2.0) * (sqrt((4.0+8.0*d/mu/g)) - 2.0) * m_to_km;
}

void assertFuzzyEquals(double act, double exp) {
    bool inrange; double merr = 1e-12; long double e;
    if (exp == 0.0)
        e = fabsl(act);
    else
        e = fabsl((act - exp) / exp);
    inrange = (e <= merr);
    if (inrange == false)
        printf("Error: Expected should be near: %0.16f , but got: %0.16f. Error -> %.16Lf\n", exp ,act, e);
    assert(1 == inrange);
}

void dotest1(double v, double mu, double expected)
{
    assertFuzzyEquals(dist(v, mu), expected);
}

void dotest2(double d, double mu, double expected)
{
    assertFuzzyEquals(speed(d, mu), expected);
}

int main() {
    printf("dist\n");
    dotest1(144, 0.3, 311.83146449201496);
    dotest1(92, 0.5, 92.12909477605366);

    printf("speed\n");
    dotest2(159, 0.8, 153.79671564846308);
    dotest2(164, 0.7, 147.91115701756493);

    return 0;
}
