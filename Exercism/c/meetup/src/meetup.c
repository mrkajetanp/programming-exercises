#include "meetup.h"
#define _XOPEN_SOURCE
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week) {
    struct tm tm;
    char buf[100];
    sprintf(buf, "%d-%d-01", year, month);
    strptime(buf, "%Y-%m-%d", &tm);

    // Get day_of_week as weekday number 0-6 (Sunday-Saturday)
    struct tm weekday_tm;
    strptime(day_of_week, "%A", &weekday_tm);
    int weekday = weekday_tm.tm_wday;

    // Day of the week on the 1st
    int weekday_on_1st = tm.tm_wday;

    // Start on the 1st
    int day_of_month = 1;
    day_of_month += (weekday - weekday_on_1st);
    if (day_of_month < 1)
        day_of_month += 7;

    int multiplier;
    if (strcmp(week, "first") == 0) {
        multiplier = 1;
    } else {
        multiplier = 0;
    }

    day_of_month += 7*(multiplier-1);

    return day_of_month;
}
