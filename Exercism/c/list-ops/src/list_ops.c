#include "list_ops.h"

list_t *new_list(size_t length, list_value_t values[]) {
    list_t* result = malloc(sizeof(list_t) + sizeof(list_value_t)*length);
    result->length = length;

    for (size_t i = 0 ; i < length ; ++i)
        result->values[i] = values[i];

    return result;
}

list_t *append_list(list_t * list1, list_t * list2) {
    size_t len = list1->length + list2->length;
    list_t* result = malloc(sizeof(list_t) + sizeof(list_value_t)*len);
    result->length = len;

    // TODO: len might be unnecessary

    size_t idx = 0;
    for (size_t i = 0 ; i < list1->length ; ++i)
        result->values[idx++] = list1->values[i];

    for (size_t i = 0 ; i < list2->length ; ++i)
        result->values[idx++] = list2->values[i];

    return result;
}

list_t *filter_list(list_t * list, bool(*filter) (list_value_t value)) {
    list_t* result = malloc(sizeof(list_t) + sizeof(list_value_t)*list->length);
    result->length = 0;

    for (size_t i = 0 ; i < list->length ; ++i) {
        if (filter(list->values[i]))
            result->values[result->length++] = list->values[i];
    }

    return result;
}

size_t length_list(list_t * list) {
    return list->length;
}

list_t *map_list(list_t * list, list_value_t(*map) (list_value_t value)) {
    list_t* result = malloc(sizeof(list_t) + sizeof(list_value_t)*list->length);
    result->length = 0;

    for (size_t i = 0 ; i < list->length ; ++i) {
        result->values[result->length++] = map(list->values[i]);
    }

    return result;
}

list_value_t foldl_list(list_t * list, list_value_t initial,
                        list_value_t(*foldl) (list_value_t value,
                                              list_value_t initial)) {


    list_value_t result = initial;

    for (size_t i = 0 ; i < list->length ; ++i)
        result = foldl(list->values[i], result);

    return result;
}

list_value_t foldr_list(list_t * list, list_value_t initial,
                        list_value_t(*foldr) (list_value_t value,
                                              list_value_t initial)) {
    list_value_t result = initial;

    for (size_t i = list->length ; i > 0 ; --i)
        result = foldr(list->values[i-1], result);

    return result;
}

list_t *reverse_list(list_t * list) {
    list_t* result = malloc(sizeof(list_t) + sizeof(list_value_t)*list->length);
    result->length = 0; 

    for (size_t i = list->length ; i > 0 ; --i)
        result->values[result->length++] = list->values[i-1];

    return result;
}

void delete_list(list_t * list) {
    free(list);
}
