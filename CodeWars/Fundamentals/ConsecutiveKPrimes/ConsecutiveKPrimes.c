#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

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

struct list* createListFromArray(int* a, int sz) {
    struct list* result = createList();

    for (int i = sz-1 ; i >= 0 ; --i)
        insertFirst(result, a[i]);

    return result;
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


int consecKprimes(int k, struct list* l) {
    int count = 0;
    bool was_prev = false;

    struct node* node = l->head;
    while (node != NULL) {
        if (n_prime(node->data) == k) {
            if (was_prev)
                count++;

            was_prev = true;
        } else {
            was_prev = false;
        }

        node = node->next;
    }

    return count;
}

void dotest(int k, struct list* l, int expr)
{
    int act = consecKprimes(k, l);
    char* s = list2String(l);
    if(act != expr)
        printf("Expected %d, got %d\n", expr, act);
    assert(act == expr);
    free(s); s = NULL;
}

int main() {
    {
        int a[] = {10081, 10071, 10077, 10065,10060, 10070, 10086, 10083,10078,
                   10076, 10089, 10085, 10063, 10074, 10068, 10073, 10072, 10075};
        struct list* l = createListFromArray(a, 18);
        dotest(2, l, 2);
    }
    {
        int a[] = {10064};
        struct list* l = createListFromArray(a, 1);
        dotest(6, l, 0);
    }
    {
        int a[] = {10054, 10039, 10053, 10051, 10047, 10043, 10037, 10034};
        struct list* l = createListFromArray(a, 8);
        dotest(1, l, 0);
    }
}
