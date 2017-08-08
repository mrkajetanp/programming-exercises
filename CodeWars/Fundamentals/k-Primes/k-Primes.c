#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

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

int n_prime(int n) {
    int result = 0;

    for (int i = 2 ; i < sqrt(n)+1 ; ++i) {
        while (n%i == 0) {
            result++;
            n /= i;
        }
    }

    if (n > 1)
        result++;

    return result;
}

struct list* kPrimes(int k, int start, int end) {
    struct list* result = createList();

    for (int i = end ; i >= start ; --i) {
        if (n_prime(i) == k)
            insertFirst(result, i);
    }

    return result;
}

int puzzle(int s) {
    struct list* one_primes = kPrimes(1, 1, s);
    struct list* three_primes = kPrimes(3, 1, s);
    struct list* seven_primes = kPrimes(7, 1, s);

    int result = 0;

    struct node* i = one_primes->head;
    while (i != NULL) {
        struct node* j = three_primes->head;
        while (j != NULL) {
            struct node* k = seven_primes->head;
            while (k != NULL) {

                if (i->data + j->data + k->data == s)
                    result++;

                k = k->next;
            }
            j = j->next;
        }
        i = i->next;
    }

    listFree(one_primes);
    listFree(three_primes);
    listFree(seven_primes);
    return result;
}

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

void dotest(int k, int start, int end, char *expr) {
    struct list* act = kPrimes(k, start, end);
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
