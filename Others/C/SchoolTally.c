#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char* name;
    char* surname;
    char* class;
    double avg;
} Student;

Student* new_student(char* name, char* surname, char* class, double avg) {
    Student* result = malloc(sizeof(Student));

    result->name = malloc(strlen(name+1));
    strcpy(result->name, name);

    result->surname = malloc(strlen(surname+1));
    strcpy(result->surname, surname);

    result->class = malloc(strlen(class+1));
    strcpy(result->class, class);

    result->avg = avg;

    return result;
}

void free_student(Student* student) {
    free(student->name);
    free(student->surname);
    free(student->class);
    free(student);
}

void read_student_array(Student** arr, FILE* file, int* size) {
    *size = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strlen(line)-1] = '\0';
        char* name = strtok(line, " ");
        char* surname = strtok(NULL, " ");
        char* class = strtok(NULL, " ");
        char* avg = strtok(NULL, " ");

        arr[(*size)++] = new_student(name, surname, class, atof(avg));
    }
}

void free_student_array(Student** arr, int size) {
    for (int i = 0 ; i < size ; ++i) {
        free_student(arr[i]);
    }
}

void print_student_array(Student** arr, int size) {
    for (int i = 0 ; i < size ; ++i) {
        printf("%s %s, %s - %f\n", arr[i]->name, arr[i]->surname,
               arr[i]->class, arr[i]->avg);
    }
}

int main() {
    FILE* input_file = fopen("szkola.txt", "r");

    Student* arr[500];
    int size = 0;
    read_student_array(arr, input_file, &size);

    print_student_array(arr, size);

    free_student_array(arr, size);
    fclose(input_file);
    return 0;
}
