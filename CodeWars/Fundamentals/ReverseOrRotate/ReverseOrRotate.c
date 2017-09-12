#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* revrot(char* s, int sz) {
    return NULL;
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

