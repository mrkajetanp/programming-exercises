#include <stdio.h>
#include "space_age.h"

static double EARTH_YEAR = 31557600.0;

double convert_planet_age(Planet planet, double seconds) {
    switch (planet) {
    case earth:
        return seconds / EARTH_YEAR;

    case mercury:
        return seconds / (EARTH_YEAR * 0.2408467);

    case venus:
        return seconds / (EARTH_YEAR * 0.61519726);

    case mars:
        return seconds / (EARTH_YEAR * 1.8808158);

    case jupiter:
        return seconds / (EARTH_YEAR * 11.862615);

    case saturn:
        return seconds / (EARTH_YEAR * 29.447498);

    case uranus:
        return seconds / (EARTH_YEAR * 84.016846);

    case neptune:
        return seconds / (EARTH_YEAR * 164.79132);
    }

    return 0;
}
