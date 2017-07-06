#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "clock.h"

void clock(time_text_t time_text, int hour, int minute) {
    if (hour < 0)
        hour = 24+(hour%24);

    if (minute >= 60) {
        hour += minute/60;
        minute -= minute/60*60;
    }

    if (minute < 0) {
        hour -= ceil((minute*-1.0)/60.0);

        if (hour < 0)
            hour += 24;

        minute += floor(minute*-1.0/60.0)*60;
        minute = 60+minute;

        if (hour < 0)
            hour = 24+(hour%24);

    }

    sprintf(time_text, "%02d:%02d", hour%24, minute);
}

void clock_add(time_text_t time_text, int minute_offset) {
    char hour_s[2];
    strncpy(hour_s, time_text, 2);
    int hour = atoi(hour_s);

    char minute_s[2];
    strncpy(minute_s, time_text+3, 2);
    int minute = atoi(minute_s);

    hour += minute_offset/60;
    minute_offset -= minute_offset/60*60;
    minute += minute_offset;

    clock(time_text, hour, minute);
}
