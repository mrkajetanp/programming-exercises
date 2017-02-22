#include <stdio.h>
#include <stdlib.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bendNo;
int len;
char key;
int life;

void record ();
void load ();
void Delay (long double);
void Move ();
void Food ();
void Score ();
void Print ();
void gotoxy (int x, int y);
void GotoXY (int x, int y);
void Bend ();
void Boarder ();
void Down ();
void Left ();
void Up ();
void Right ();
void ExitGame ();
int Scoreonly ();

typedef struct Coordinate {
    int x;
    int y;
    int direction;
} Coordinate;

Coordinate head, bend[500], food, body[30];

int main () {
    Print ();
    printf ("Game goes here..\n");
    system ("clear");
    load ();

    return 0;
}

void Print () {
    /* GotoXY (10, 12); */
    printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
    getchar ();
    system ("clear");
    printf ("\tGame instructions:\n");
    printf ("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press 'q'. \n");
    printf ("\n\nPress any key to play game...");

    if (getchar() == 'q')
        exit (0);
}


