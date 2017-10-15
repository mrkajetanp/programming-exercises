#include <stdio.h>

typedef struct _student_data {
    char surname[25];
    char grades[17];
} StudentData;

const char* subject[] = {"Rel", "Pol", "Eng", "Ger", "Fre",
                           "His", "CSt", "Mat", "Phy", "Che", "Bio",
                           "Geo", "ITe", "SEd", "PEd", "CKn", "BBa"};

void handle_sigle_data(FILE* file, StudentData* student) {
    fread(student, sizeof(*student), 1, file);
    student->surname[24] = '\0';

    for (int i = 0 ; i < 24 ; ++i) {
        if (student->surname[i] == -120)
            student->surname[i] = 'l';

        if (student->surname[i] == -28)
            student->surname[i] = 'n';

        if (student->surname[i] == -94)
            student->surname[i] = 'o';

        if (student->surname[i] == -99)
            student->surname[i] = 'L';

        if (student->surname[i] == -91)
            student->surname[i] = 'a';

        if (student->surname[i] == -105)
            student->surname[i] = 'S';

        if (student->surname[i] == -85)
            student->surname[i] = 'z';
    }
}

void print_vertical_separator() {
    printf("+-----+-------------------------+");
    for (int i = 0 ; i < 17 ; ++i)
        printf("-----+");
    printf("---------+\n");
}

int main() {
    FILE* data_file = fopen("k1e.dat", "rb");

    print_vertical_separator();
    printf("| Num | Name and Surname        |");
    for (int i = 0 ; i < 17 ; ++i)
        printf(" %s |", subject[i]);
    printf(" Average |");
    printf("\n");

    print_vertical_separator();

    StudentData temp_student;
    for (int i = 0 ; i < 31 ; ++i) {
        handle_sigle_data(data_file, &temp_student);

        printf("| %-3d | %s|", i+1, temp_student.surname);
        double sum = 0;
        for (int j = 0 ; j < 17 ; ++j) {
            sum += temp_student.grades[j];
            printf("  %-2d |", temp_student.grades[j]);
        }
        printf("  %-2.2f   |", sum/17.0);

        printf("\n");
    }
    print_vertical_separator();

    fclose(data_file);
    return 0;
}
