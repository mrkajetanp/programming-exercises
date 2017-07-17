#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int cmp_char(const void* a, const void* b) {
    if (*(char*)a > *(char*)b)
        return -1;
    else if (*(char*)a < *(char*)b)
        return 1;

    return 0;
}

char* sortTheInnerContent(const char* words, int length) {
    char* result = malloc(length);
    strcpy(result, "");

    char buff[length];
    strcpy(buff, words);

    char other_buff[length];
    strcpy(other_buff, " ");

    char* word = strtok(buff, " ");
    while (word != NULL) {
        if (strlen(word) <= 3) {
            strcat(result, word);
            strcat(result, " ");
            word = strtok(NULL, " ");
            continue;
        }

        strncat(result, &word[0], 1);
        strcpy(other_buff, word+1);
        other_buff[strlen(other_buff)-1] = '\0';

        qsort(other_buff, strlen(other_buff), sizeof(char), cmp_char);
        strcat(result, other_buff);

        strncat(result, &word[strlen(word)-1], 1);
        strcat(result, " ");

        word = strtok(NULL, " ");
    }

    return result;
}

void assertString(char* actual, char* expected, int length) {
  printf("\nYour result:     %s\nExpected result: %s\n", actual, expected);

  for(int i=0;i<length;i++) {
    if(actual[i] != expected[i])
        assert(actual[i] == expected[i]);
  }
}

int main() {
    char* words1 = "sort the inner content in descending order";
    char* expected1 = "srot the inner ctonnet in dsnnieedcg oredr";
    assertString(sortTheInnerContent(words1, strlen(words1)),
                 expected1, strlen(words1));

    char* words2 = "wait for me";
    char* expected2 = "wiat for me";
    assertString(sortTheInnerContent(words2, strlen(words2)),
                 expected2, strlen(words2));

    char* words3 = "this kata is easy";
    char* expected3 = "tihs ktaa is esay";
    assertString(sortTheInnerContent(words3, strlen(words3)),
                 expected3, strlen(words3));

    return 0;
}
