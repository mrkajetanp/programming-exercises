#include "triangle.h"

bool is_equilateral(Triangle_t* tr) {
    if (tr->a == 0 || tr->b == 0 || tr->c == 0 || tr->a + tr->b < tr->c ||
        tr->a + tr->c < tr->b || tr->b + tr->c < tr->a)
        return false;


    return (tr->a == tr->b) && (tr->b == tr->c);
}

bool is_isosceles(Triangle_t* tr) {
    if (tr->a == 0 || tr->b == 0 || tr->c == 0 || tr->a + tr->b < tr->c ||
        tr->a + tr->c < tr->b || tr->b + tr->c < tr->a)
        return false;

    return (tr->a == tr->b) || (tr->b == tr->c) || (tr->a == tr->c);
}

bool is_scalene(Triangle_t* tr) {
    if (tr->a == 0 || tr->b == 0 || tr->c == 0 || tr->a + tr->b < tr->c ||
        tr->a + tr->c < tr->b || tr->b + tr->c < tr->a)
        return false;

    return (tr->a != tr->b) && (tr->b != tr->c) && (tr->a != tr->c);
}
