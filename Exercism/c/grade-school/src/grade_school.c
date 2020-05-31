#include "grade_school.h"
#include <stdlib.h>
#include <string.h>

int student_cmp(const void*, const void*);

#define grade_cmp(a, b) ((a > b) - (a < b))
int student_cmp(const void* a, const void* b) {
    student_t* st_a = (student_t*)a;
    student_t* st_b = (student_t*)b;

    if (grade_cmp(st_a->grade, st_b->grade) != 0)
        return grade_cmp(st_a->grade, st_b->grade);

    return strcmp(st_a->name, st_b->name);
}

static roster_t roster = {
    .count = 0,
};

roster_t get_roster() {
    return roster;
}

void clear_roster() {
    roster.count = 0;
}

bool add_student(char* name, uint8_t grade) {
    roster.students[roster.count].name = name;
    roster.students[roster.count].grade = grade;
    roster.count++;
    qsort(roster.students, roster.count, sizeof(student_t), student_cmp);
    return true;
}


roster_t get_grade(uint8_t grade) {
    roster_t result = { 0 };

    for (size_t i = 0 ; i < roster.count ; ++i) {
        if (roster.students[i].grade == grade) {
            result.students[result.count].name = roster.students[i].name;
            result.students[result.count++].grade = grade;
        }
    }

    return result;
}
