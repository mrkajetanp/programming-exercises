#include <string.h>
#include <stdio.h>
#include "beer_song.h"

void verse(char* buffer, int x) {
    switch (x) {
    case 0:
        strcpy(buffer,
               "No more bottles of beer on the wall, no more bottles of beer.\n"
               "Go to the store and buy some more, "
               "99 bottles of beer on the wall.\n");
        break;

    case 1:
        strcpy(buffer,
               "1 bottle of beer on the wall, 1 bottle of beer.\n"
               "Take it down and pass it around, "
               "no more bottles of beer on the wall.\n");
        break;

    case 2:
        strcpy(buffer, "2 bottles of beer on the wall, 2 bottles of beer.\n"
                "Take one down and pass it around, "
                "1 bottle of beer on the wall.\n");
        break;

    default:
        sprintf(buffer, "%d bottles of beer on the wall, %d bottles of beer.\n"
                "Take one down and pass it around, "
                "%d bottles of beer on the wall.\n",
                x, x, x-1);
        break;
    }
}

void sing(char* buff, int from, int to) {
    strcpy(buff, "");

    char temp[1024];
    for (int i = from ; i >= to ; --i) {
        verse(temp, i);
        strcat(buff, temp);
        if (i != to)
            strcat(buff, "\n");
    }
}
