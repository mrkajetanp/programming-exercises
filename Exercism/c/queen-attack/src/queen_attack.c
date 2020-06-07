#include "queen_attack.h"
#include <stdlib.h>
#include <stdbool.h>

#define is_position_valid(x) ((x.row >= 0 && x.row < 8) && (x.column >= 0 && x.column < 8))

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    // Check if both queens are on valid positions
    if (!(is_position_valid(queen_1) && is_position_valid(queen_2)))
        return INVALID_POSITION;

    // Check if queens have different positions from each other
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
        return INVALID_POSITION;

    // Can attack on row or column
    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column)
        return CAN_ATTACK;

    // Can attack on diagonal
    if (abs(queen_1.row-queen_2.row) == abs(queen_1.column-queen_2.column))
        return CAN_ATTACK;

    return CAN_NOT_ATTACK;
}
