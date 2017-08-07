#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int* nbMonths(int start_price_old, int start_price_new,
              int saving_per_month, double percent_loss_by_month) {
    int* result = malloc(2 * sizeof *result);

    if (start_price_old >= start_price_new) {
        result[0] = 0;
        result[1] = start_price_old-start_price_new;
        return result;
    }

    int month = 1;
    double old = start_price_old;
    double new = start_price_new;
    double account = 0.0;

    while (1) {
        if (month%2 == 0)
            percent_loss_by_month += 0.5;


        old -= old * (percent_loss_by_month/100.0);
        new -= new * (percent_loss_by_month/100.0);
        account += saving_per_month;

        if (account+old >= new)
            break;

        month += 1;
    }

    result[0] = month;
    result[1] = round(account+old-new);

    return result;
}

char* array2StringInt(int* array, size_t sz) {
    char* result = malloc(sz * 10);
    strcpy(result, "[");

    char buff[15];
    for (size_t i = 0 ; i < sz ; ++i) {
        sprintf(buff, "%d", array[i]);
        strcat(result, buff);
        strcat(result, ", ");
    }
    result[strlen(result)-2] = '\0';
    strcat(result, "]");

    return result;
}

void dotest(int start_price_old, int start_price_new,
            int saving_per_month, double percent_loss_by_month, int *expr) {
    char* sexpr = array2StringInt(expr, 2);
    int *act = nbMonths(start_price_old, start_price_new,
                        saving_per_month, percent_loss_by_month);
    char* sact = array2StringInt(act, 2);
    if(strcmp(sact, sexpr) != 0)
        printf("Error. Expected %s but got %s\n", sexpr, sact);
    assert(strcmp(sact, sexpr) == 0);
    free(sact); sact = NULL;
    free(sexpr); sexpr = NULL;
    free(act); act = NULL;
}

int main() {
      {
          int r1[2] = { 6, 766 };
          dotest(2000, 8000, 1000, 1.5, r1);
      }
      {
          int r1[2] = { 0, 4000 };
          dotest(12000, 8000, 1000, 1.5, r1);
      }
      {
          int r1[2] = { 8, 597 };
          dotest(8000, 12000, 500, 1, r1);
      }
}

