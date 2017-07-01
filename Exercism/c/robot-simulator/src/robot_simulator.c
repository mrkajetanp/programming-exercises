#include <string.h>
#include "robot_simulator.h"

RobotGridStatus_t robot_init(void) {
    RobotGridStatus_t robot =
        { Default_Bearing, {Default_X_Coordinate, Default_Y_Coordinate} };

    return robot;
}

RobotGridStatus_t robot_init_with_position(int bearing, int x, int y) {
    if (bearing > Heading_Max)
        bearing = Default_Bearing;

    RobotGridStatus_t robot = { bearing, {x, y} };

    return robot;
}

void robot_turn_right(RobotGridStatus_t* robot) {
    switch (robot->bearing) {
    case Heading_North:
        robot->bearing = Heading_East;
        break;

    case Heading_East:
        robot->bearing = Heading_South;
        break;

    case Heading_West:
        robot->bearing = Heading_North;
        break;

    case Heading_South:
        robot->bearing = Heading_West;
        break;

    case Heading_Max:
        break;
    }
}

void robot_turn_left(RobotGridStatus_t* robot) {
    switch (robot->bearing) {
    case Heading_North:
        robot->bearing = Heading_West;
        break;

    case Heading_East:
        robot->bearing = Heading_North;
        break;

    case Heading_West:
        robot->bearing = Heading_South;
        break;

    case Heading_South:
        robot->bearing = Heading_East;
        break;

    case Heading_Max:
        break;
    }
}

void robot_advance(RobotGridStatus_t* robot) {
    switch (robot->bearing) {
    case Heading_North:
        robot->grid.y_position++;
        break;

    case Heading_East:
        robot->grid.x_position++;
        break;

    case Heading_West:
        robot->grid.x_position--;
        break;

    case Heading_South:
        robot->grid.y_position--;
        break;

    case Heading_Max:
        break;
    }
}

void robot_simulator(RobotGridStatus_t* robot, const char *commands) {
    for (size_t i = 0 ; i < strlen(commands) ; ++i) {
        switch (commands[i]) {
        case 'R':
            robot_turn_right(robot);
            break;

        case 'L':
            robot_turn_left(robot);
            break;

        case 'A':
            robot_advance(robot);
            break;
        }
    }
}

