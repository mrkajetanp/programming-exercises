#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void word_to_upper(char* word) {
    for (size_t i = 0 ; i < strlen(word) ; ++i)
        word[i] = toupper(word[i]);
}

void word_to_lower(char* word) {
    for (size_t i = 0 ; i < strlen(word) ; ++i)
        word[i] = tolower(word[i]);
}

char* arrange(char* str) {
    char buff[strlen(str)+1];
    strcpy(buff, str);

    /* calculate how many words there are */
    int len = 1;
    for (size_t i = 0 ; i < strlen(str) ; ++i) {
        if (str[i] == ' ')
            len++;
    }

    if (len < 2)
        return str;

    /* create an array with separated words */
    char *words[len];
    len = 0;
    char* tok = strtok(buff, " ");
    while (tok != NULL) {
        words[len] = malloc(strlen(tok)+1);
        if (!words[len])
            return NULL;

        strcpy(words[len++], tok);
        tok = strtok(NULL, " ");
    }

    /* arrange */
    for (int i = 0 ; i < len-1 ; ++i) {
        if (i%2 == 0) {
            if (!(strlen(words[i]) <= strlen(words[i+1]))) {
                swap(&words[i], &words[i+1]);
            }
            word_to_lower(words[i]);
        } else {
            if (!(strlen(words[i]) >= strlen(words[i+1])))
                swap(&words[i], &words[i+1]);
            word_to_upper(words[i]);
        }
    }

    /* set the last word to the proper case */
    if (len%2 == 0) {
        word_to_upper(words[len-1]);
    } else {
        word_to_lower(words[len-1]);
    }

    /* join words into the final string */
    char* result = malloc(strlen(str)+1);
    if (!result)
        return NULL;

    strcpy(result, "");
    for (int i = 0 ; i < len ; ++i) {
        strcat(result, words[i]);
        strcat(result, " ");
    }
    result[strlen(result)-1] = '\0';

    /* free the array of words */
    for (int i = 0 ; i < len ; ++i) {
        if (words[i])
            free(words[i]);
    }

    return result;
}

void dotest(char* s, char *expr) {
    char *sact = arrange(s);
    if(strcmp(sact, expr) != 0)
        printf("playPass. Error. Expected \n|%s|\n but got \n|%s|\n", expr, sact);
    assert(strcmp(sact, expr) == 0);
}

int main() {
    {
        char* s = "who hit retaining The That a we taken";
        dotest(s, "who RETAINING hit THAT a THE we TAKEN"); // 3
    }
    {
        char* s = "on I came up were so grandmothers";
        char* sol = "i CAME on WERE up GRANDMOTHERS so";
        dotest(s, sol); // 4
    }
    {
        char* s = "way the my wall them him";
        char* sol = "way THE my WALL him THEM";
        dotest(s, sol); // 1
    }
}
