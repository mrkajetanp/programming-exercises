#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool if_reverse(char* s) {
    return s;
}

char* reverse(char* s) {
    return s;
}

char* rotate(char* s) {
    return s;
}

char* revrot(char* s, int sz) {
    if (sz <= 0)
        return "";

    size_t len = strlen(s);

    char* result = malloc(len);
    strcpy(result, "");

    size_t idx = 0;
    while (idx <= len) {
        char* temp = strndup(s+idx, sz);

        printf("%s\n", temp);
        idx += sz;

        if (idx+sz > len)
            break;
    }

    strcat(result, strndup(s+idx, sz));
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

