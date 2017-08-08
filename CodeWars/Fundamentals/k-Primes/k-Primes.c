#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



struct node {
    int data;
    struct node *next;
};

struct list {
    size_t sz;
    struct node *head;
};

struct list* createList() {
    struct list* result = malloc(sizeof(*result));
    result->sz = 0;
    result->head = NULL;
    return result;
}

void insertFirst(struct list* l, int data) {
    struct node* new_head = malloc(sizeof(*new_head));
    new_head->data = data;
    new_head->next = l->head;
    l->head = new_head;
}

void listFree(struct list* l) {
    struct node* node = l->head;

    while (node != NULL) {
        struct node* tmp = node->next;
        free(node);
        node = tmp;
    }

    free(l);
}

/* struct list* reverse(struct list* l) { */
/* } */

char* list2String(struct list* l) {
    char* result = malloc(600);
    strcpy(result, "[ ");
    struct node* node = l->head;
    char buff[100];

    while (node != NULL) {
        sprintf(buff, "%d ", node->data);
        strcat(result, buff);
        node = node->next;
    }

    strcat(result, "]");
    return result;
}

struct list* kPrimes(int k, int start, int nd) {
    struct list* result = createList();
    insertFirst(result, 8);
    insertFirst(result, 3);

    return result;
}

int puzzle(int s) {
    // your code
    return 0;
}

void dotest(int k, int start, int nd, char *expr) {
    struct list* act = kPrimes(k, start, nd);
    char* sact = list2String(act);
    if(strcmp(sact, expr) != 0)
        printf("kPrimes. Error. Expected \n%s\n but got \n%s\n", expr, sact);
    assert(strcmp(sact, expr) == 0);

    listFree(act); act = NULL;
    free(sact); sact = NULL;
}
void dotest1(int s, int expr) {
    int act = puzzle(s);
    if(act != expr)
        printf("Expected %d, got %d\n", expr, act);
    assert(act == expr);
}

int main() {

    printf("Testing kPrimes\n");
    {
        dotest(5, 1000, 1040, "[ 1020 1026 1032 ]");
        dotest(5, 1000, 1100, "[ 1020 1026 1032 1044 1050 1053 1064 1072 1092 1100 ]");
    }

    printf("Testing puzzle\n");
    dotest1(138, 1);
    dotest1(143, 2);
}
