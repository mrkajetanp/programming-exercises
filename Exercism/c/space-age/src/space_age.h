#ifndef SPACE_AGE_H
#define SPACE_AGE_H

typedef enum planet {
    earth,
    mercury,
    venus,
    mars,
    jupiter,
    saturn,
    uranus,
    neptune,
} Planet;

double convert_planet_age(Planet, double);

#endif
