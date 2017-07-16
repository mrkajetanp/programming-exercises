#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node * reverse_list(struct Node *node) {
    if (node == NULL)
        return NULL;

    if (node->next == NULL)
        return node;

    /* calculate the length */
    int len= 0;
    struct Node* curr = node;
    while (curr != NULL) {
        curr = curr->next;
        len++;
    }

    /* temporary list */
    struct Node** array_list = malloc(len * sizeof(struct Node*));
    curr = node;

    /* set the "first" node (last in the final list) */
    array_list[0] = curr;
    curr = curr->next;
    array_list[0]->next = NULL;

    /* set the rest of the nodes */
    for (int i = 1 ; i < len ; ++i) {
        array_list[i] = curr;
        curr = curr->next;
        array_list[i]->next = array_list[i-1];
    }

    curr = array_list[len-1];
    free(array_list);
    return curr;
}


int main() {
    {
        struct Node input[3];
        struct Node expected[3];
        input[0].value = 1; input[0].next = &input[1];
        input[1].value = 2; input[1].next = &input[2];
        input[2].value = 3; input[2].next = NULL;
        expected[0].value = 3; expected[0].next = &expected[1];
        expected[1].value = 2; expected[1].next = &expected[2];
        expected[2].value = 1; expected[2].next = NULL;
        struct Node* result = reverse_list(input);

        assert(result != NULL);
        assert(result->value == 3);
        assert(result->next != NULL);
        assert(result->next->value == 2);
        assert(result->next->next != NULL);
        assert(result->next->next->value == 1);
    }
}
