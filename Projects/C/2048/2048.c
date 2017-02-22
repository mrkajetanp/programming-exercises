#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define D_INVALID -1
#define D_UP 1
#define D_DOWN 2
#define D_RIGHT 3
#define D_LEFT 4

struct gamestate__ {
    int grid[4][4];
    int haveMoved;
    long totalScore;
    long scoreLastMove;
    int blocksInPlay;
} game;

const long values[] = {
    0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048
};

const char *colors[] = {
    "39", "31", "32", "33", "34", "35", "36", "37", "91", "92", "93", "94"
};

/* structures containing the state of the terminal */
struct termios oldt, newt;

void doNewBlock (void);
void doDraw (void);
int tick (int d);
void merge (int d);
void gravitate (int d);
int checkEndCondition (void);
void gameWin (void);
void gameLose (void);
void gameQuit (void);

void _mergeLeft (void);
void _mergeRight (void);
void _mergeUp (void);
void _mergeDown (void);

void _gravitateLeft (void);
void _gravitateRight (void);
void _gravitateUp (void);
void _gravitateDown (void);

int main () {
    /* Initialize terminal settings */
    tcgetattr (STDIN_FILENO, &oldt);
    newt = oldt;
    /* disable canonical mode and echoing characters in new settings */
    newt.c_lflag &= ~(ICANON | ECHO);
    /* set new settings from the newt termios, TCSANOW = do it now) */
    tcsetattr (STDIN_FILENO, TCSANOW, &newt);

    srand (time(NULL));
    memset (&game, sizeof(game), 0); /* set the memory for game struct */
    doNewBlock (); /* add a new block with either 1 or 2 */
    doNewBlock ();
    doDraw ();

    while (1) {
        int foundValidKey, direction, value;
        do {
            foundValidKey = 1;
            direction = D_INVALID;
            value = getchar ();

            switch (value) {
            case 'h':
                direction = D_LEFT;
                break;
            case 'l':
                direction = D_RIGHT;
                break;
            case 'j':
                direction = D_DOWN;
                break;
            case 'k':
                direction = D_UP;
                break;
            case 'q':
                gameQuit ();
                break;
            case 27:
                if (getchar() == '[') {
                    value = getchar ();
                    switch (value) {
                    case 'A':
                        direction = D_UP;
                        break;
                    case 'B':
                        direction = D_DOWN;
                        break;
                    case 'C':
                        direction = D_RIGHT;
                        break;
                    case 'D':
                        direction = D_LEFT;
                        break;
                    default:
                        foundValidKey = 0;
                        break;
                    }
                }
                break;
            default:
                foundValidKey = 0;
                break;
            }
        } while (!foundValidKey);

        tick (direction);
        if (game.haveMoved != 0)
            doNewBlock ();

        doDraw ();

        switch (checkEndCondition()) {
        case -1:
            gameLose ();
        case 1:
            gameWin ();
        case 0:
            break;
        } // game loop ends
    }

    tcsetattr (STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}

/* creates a new block on the board */
void doNewBlock () {
    if (game.blocksInPlay >= 16)    return;

    int bn = rand () % (16 - game.blocksInPlay);
    int pn = 0;

    int x, y;
    for (x = 0 ; x < 4 ; ++x) {
        for (y = 0 ; y < 4 ; ++y) {
            if (game.grid[x][y])
                continue;

            if (pn == bn) {
                game.grid[x][y] = (rand()%10) ? 1 : 2;
                game.blocksInPlay++;
                return;
            }
            else
                ++pn;
        }
    }
}

/* draws the board */
void doDraw () {
    printf ("\033[2J\033[HScore: %ld", game.totalScore);
    if (game.scoreLastMove)
        printf (" (+%ld)", game.scoreLastMove);
    printf ("\n");

    int i;
    for (i = 0 ; i < 25 ; ++i)
        printf ("-");
    printf ("\n");

    int y, x;
    for (y = 0 ; y < 4 ; ++y) {
        printf ("|");
        for (x = 0 ; x < 4 ; ++x) {
            if (game.grid[x][y])
                printf ("\033[7m\033[%sm%*zd \033[0m|", colors[game.grid[x][y]],
                        4, values[game.grid[x][y]]);
            else
                printf ("%*s |", 4, "");
        }
        printf ("\n");
    }

    for (i = 0 ; i < 25 ; ++i)
        printf ("-");
    printf ("\n");
}

int tick (int d) {
    game.haveMoved = 0;
    gravitate (d);
    merge (d);
    gravitate (d);
    return game.haveMoved;
}

void merge (int d) {
    game.scoreLastMove = 0;

    switch (d) {
    case D_LEFT:
        _mergeLeft ();
        break;
    case D_RIGHT:
        _mergeRight ();
        break;
    case D_DOWN:
        _mergeDown ();
        break;
    case D_UP:
        _mergeUp ();
        break;
    }
}

void _mergeLeft () {
    int x, y;
    do {
        for (x = 0 ; x < 3 ; ++x) {
            for (y = 0 ; y < 4 ; y++) {
                if (game.grid[x][y] && (game.grid[x][y] == game.grid[x+1][y])) {
                    game.grid[x][y] += (game.haveMoved = 1);
                    game.grid[x+1][y] = (0 * game.blocksInPlay--);
                    game.scoreLastMove += values[game.grid[x][y]];
                    game.totalScore += values[game.grid[x][y]];
                }
            }
        }
    } while (0);
}

void _mergeRight () {
    int x, y;
    do {
        for (x = 3 ; x > 0 ; --x) {
            for (y = 0 ; y < 4 ; y++) {
                if (game.grid[x][y] && (game.grid[x][y] == game.grid[x-1][y])) {
                    game.grid[x][y] += (game.haveMoved = 1);
                    game.grid[x-1][y] = (0 * game.blocksInPlay--);
                    game.scoreLastMove += values[game.grid[x][y]];
                    game.totalScore += values[game.grid[x][y]];
                }
            }
        }
    } while (0);
}

void _mergeDown () {
    int x, y;
    do {
        for (y = 3 ; y > 0 ; --y) {
            for (x = 0 ; x < 4 ; x++) {
                if (game.grid[x][y] && (game.grid[x][y] == game.grid[x][y-1])) {
                    game.grid[x][y] += (game.haveMoved = 1);
                    game.grid[x][y-1] = (0 * game.blocksInPlay--);
                    game.scoreLastMove += values[game.grid[x][y]];
                    game.totalScore += values[game.grid[x][y]];
                }
            }
        }
    } while (0);
}

void _mergeUp () {
    int x, y;
    do {
        for (y = 0 ; y < 3 ; ++y) {
            for (x = 0 ; x < 4 ; x++) {
                if (game.grid[x][y] && (game.grid[x][y] == game.grid[x][y+1])) {
                    game.grid[x][y] += (game.haveMoved = 1);
                    game.grid[x][y+1] = (0 * game.blocksInPlay--);
                    game.scoreLastMove += values[game.grid[x][y]];
                    game.totalScore += values[game.grid[x][y]];
                }
            }
        }
    } while (0);
}

void gravitate (int d) {
    switch (d) {
    case D_LEFT:
        _gravitateLeft ();
        break;
    case D_RIGHT:
        _gravitateRight ();
        break;
    case D_DOWN:
        _gravitateDown ();
        break;
    case D_UP:
        _gravitateUp ();
        break;
    }
}

void _gravitateLeft () {
    int x, y;
    do {
        int breakCond = 0;
        while (!breakCond) {
            breakCond = 1;
            for (x = 0 ; x < 3 ; ++x) {
                for (y = 0 ; y < 4 ; ++y) {
                    if (!game.grid[x][y] && game.grid[x+1][y]) {
                        game.grid[x][y] = game.grid[x+1][y];
                        game.grid[x+1][y] = breakCond = 0;
                        game.haveMoved = 1;
                    }
                }
            }
            doDraw ();
            usleep (40000);
        }
    } while (0);
}

void _gravitateRight () {
    int x, y;
    do {
        int breakCond = 0;
        while (!breakCond) {
            breakCond = 1;
            for (x = 3 ; x > 0 ; --x) {
                for (y = 0 ; y < 4 ; ++y) {
                    if (!game.grid[x][y] && game.grid[x-1][y]) {
                        game.grid[x][y] = game.grid[x-1][y];
                        game.grid[x-1][y] = breakCond = 0;
                        game.haveMoved = 1;
                    }
                }
            }
            doDraw ();
            usleep (40000);
        }
    } while (0);
}

void _gravitateDown () {
    int x, y;
    do {
        int breakCond = 0;
        while (!breakCond) {
            breakCond = 1;
            for (y = 3 ; y > 0 ; --y) {
                for (x = 0 ; x < 4 ; ++x) {
                    if (!game.grid[x][y] && game.grid[x][y-1]) {
                        game.grid[x][y] = game.grid[x][y-1];
                        game.grid[x][y-1] = breakCond = 0;
                        game.haveMoved = 1;
                    }
                }
            }
            doDraw ();
            usleep (40000);
        }
    } while (0);
}

void _gravitateUp () {
    int x, y;
    do {
        int breakCond = 0;
        while (!breakCond) {
            breakCond = 1;
            for (y = 0 ; y < 3 ; ++y) {
                for (x = 0 ; x < 4 ; ++x) {
                    if (!game.grid[x][y] && game.grid[x][y+1]) {
                        game.grid[x][y] = game.grid[x][y+1];
                        game.grid[x][y+1] = breakCond = 0;
                        game.haveMoved = 1;
                    }
                }
            }
            doDraw ();
            usleep (40000);
        }
    } while (0);
}

int checkEndCondition () {
    int ret = -1;
    int x, y;
    for (x = 0 ; x < 4 ; ++x) {
        for (y = 0 ; y < 4 ; ++y) {
            if (values[game.grid[x][y]] == 2048)
                return 1;
            if (!game.grid[x][y] ||
                ((x+1 < 4) && (game.grid[x][y] == game.grid[x+1][y])) ||
                ((y + 1 < 4) && (game.grid[x][y] == game.grid[x][y+1])))
                ret = 0;
        }
    }
    return ret;
}

void gameWin () {
    printf ("You win!\n");
    gameQuit ();
}

void gameLose () {
    printf ("You lose!\n");
    gameQuit ();
}

void gameQuit () {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    exit (0);
}

