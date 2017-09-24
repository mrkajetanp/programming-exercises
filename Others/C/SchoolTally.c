/***************************************************************************
 * This is free and unencumbered software released into the public domain. *
 *                                                                         *
 * Anyone is free to copy, modify, publish, use, compile, sell, or         *
 * distribute this software, either in source code form or as a compiled   *
 * binary, for any purpose, commercial or non-commercial, and by any       *
 * means.                                                                  *
 *                                                                         *
 * In jurisdictions that recognize copyright laws, the author or authors   *
 * of this software dedicate any and all copyright interest in the         *
 * software to the public domain. We make this dedication for the benefit  *
 * of the public at large and to the detriment of our heirs and            *
 * successors. We intend this dedication to be an overt act of             *
 * relinquishment in perpetuity of all present and future rights to this   *
 * software under copyright law.                                           *
 *                                                                         *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,         *
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF      *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  *
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR       *
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,   *
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR   *
 * OTHER DEALINGS IN THE SOFTWARE.                                         *
 *                                                                         *
 * For more information, please refer to <https://unlicense.org            *
 ***************************************************************************/

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
        char* temp[5];
        temp[0] = strtok(line, " ");
        temp[1] = strtok(NULL, " ");
        temp[2] = strtok(NULL, " ");
        temp[3] = strtok(NULL, " ");
        temp[4] = strtok(NULL, " ");

        if (!temp[4])
            arr[(*size)++] = new_student(temp[1], temp[0], temp[2], atof(temp[3]));
        else
            arr[(*size)++] = new_student(temp[1], temp[0], temp[3], atof(temp[4]));
    }
}

void free_student_array(Student** arr, int size) {
    for (int i = 0 ; i < size ; ++i) {
        free_student(arr[i]);
    }
}

void print_student_array(Student** arr, int size) {
    for (int i = 0 ; i < size ; ++i) {
        printf("%d. %s %s, %s - %f\n",
               i+1, arr[i]->surname, arr[i]->name, arr[i]->class, arr[i]->avg);
    }
}

int count_students_class(Student** arr, int size,
                         char* class, int* girls) {
    int total = 0;
    *girls = 0;

    for (int i = 0 ; i < size ; ++i) {
        if (strcmp(arr[i]->class, class) == 0) {
            if (arr[i]->name[strlen(arr[i]->name)-1] == 'a')
                (*girls)++;

            total++;
        }
    }

    return total;
}

double class_average(Student** arr, int size, char* class) {
    double sum = 0;

    int class_size = 0;
    for (int i = 0 ; i < size ; ++i) {
        if (strcmp(arr[i]->class, class) == 0) {
            sum += arr[i]->avg;
            class_size++;
        }
    }

    if (class_size == 0)
        return 0;

    return sum/(double)class_size;
}

void print_student_tally(Student** arr, int size) {
    int temp_girls = 0;

    char* classes[] = {
        "1a", "1b", "1c", "1d", "1e", "1f", "1g",
        "2a", "2b", "2c", "2d", "2e", "2f", "2g",
    };

    for (size_t i = 0 ; i < 14 ; ++i) {
        char temp[5];
        strcpy(temp, "kl");
        strcat(temp, classes[i]);

        int total = count_students_class(arr, size, temp, &temp_girls);
        printf("Class %s: Students - %d, Boys - %d, Girls - %d, Average: %.2f\n",
               classes[i], total, total-temp_girls, temp_girls,
               class_average(arr, size, temp));

        if (i == 6)
            printf("\n");
    }
}

int main() {
    FILE* input_file = fopen("szkola.txt", "r");
    Student* arr[500];
    int size = 0;
    read_student_array(arr, input_file, &size);

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    printf("**School Tally**\n\nChoose an option:\n");
    printf("1. Student list\n");
    printf("2. Student tally\n");

    int ch;
    while ((ch = getchar()) != 27) {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        printf("**School Tally**\n\nChoose an option:\n");
        printf("1. Student list\n");
        printf("2. Student tally\n");

        switch (ch) {
        case '1':
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            print_student_array(arr, size);
            getchar();
            break;

        case '2':
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif

            print_student_tally(arr, size);
            getchar();
            break;
        }
    }

    free_student_array(arr, size);
    fclose(input_file);
    return 0;
}
