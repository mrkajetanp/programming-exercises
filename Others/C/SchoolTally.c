#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char* name;
    char* surname;
    char* class;
    double avg;
} Student;

Student* new_student(char* name, char* surname, char* class, char* avg) {
    Student* result = malloc(sizeof(Student));

    result->name = malloc(strlen(name+1));
    strcpy(result->name, name);
    result->surname = malloc(strlen(surname+1));
    strcpy(result->surname, surname);
    result->class = malloc(strlen(class+1));
    strcpy(result->class, class);
    result->avg = atof(avg);

    return result;
}

void print_student_list(FILE* file) {
    char line[256];

    int lines = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strlen(line)-1] = '\0';
        char* name = strtok(line, " ");
        char* surname = strtok(NULL, " ");
        char* class = strtok(NULL, " ");
        char* avg = strtok(NULL, " ");

        printf("%s %s, %s - %s\n", name, surname, class, avg);
    }

    printf("\nlines: %d \n", lines);
}

int main() {
    FILE* input_file = fopen("szkola.txt", "r");

    print_student_list(input_file);

    fclose(input_file);
    return 0;
}
