#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

bool if_reverse(char* s) {
    long sum = 0;

    for (size_t i = 0 ; i < strlen(s) ; ++i)
        sum += pow(s[i]-'0', 3);

    return sum%2 == 0;
}

char* reverse(char* s) {
    char* result = malloc(strlen(s));
    strcpy(result, "");

    int idx = 0;
    for (int i = strlen(s)-1 ; i >= 0 ; --i)
        result[idx++] = s[i];
    result[idx] = '\0';

    free(s);
    return result;
}

char* rotate(char* s) {
    char* result = malloc(strlen(s));
    strcpy(result, "");

    strcat(result, strdup(s+1));
    size_t len = strlen(result);
    result[len++] = s[0];
    result[len] = '\0';

    free(s);
    return result;
}

char* revrot(char* s, int sz) {
    printf("%s %d \n", s, sz);
    size_t len = strlen(s);

    char* result = malloc(len);
    strcpy(result, "");

    if (sz <= 0 || (size_t)sz > len)
        return result;

    size_t idx = 0;
    while (idx <= len) {
        char* temp = strndup(s+idx, sz);

        if (if_reverse(temp))
            strcat(result, reverse(temp));
        else
            strcat(result, rotate(temp));

        idx += sz;
        if (idx+sz > len)
            break;
    }

    return result;
}

void dotest(char* s, size_t sz, char *expr)
{
    char *act = revrot(s, sz);
    if(strcmp(act, expr) != 0)
        printf("Error. Expected %s but got %s\n", expr, act);
    assert(strcmp(act, expr) == 0);
}

int main() {

    char s[]= "1234";
    dotest(s, 0, "");
    char s1[] = "";
    dotest(s1, 0, "");
    char s2[] = "1234";
    dotest(s2, 5, "");
    char s3[] = "733049910872815764";
    dotest(s3, 5, "330479108928157");
    char s4[] = "73304991087281576455176044327690580265896";
    dotest(s4, 8, "1994033775182780067155464327690480265895");

}

