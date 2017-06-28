#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "allergies.h"

/* printf("next: %d \n", ); */

bool is_allergic_to(Allergen_t gen, int score) {
    Allergen_List_t list;
    get_allergens(score, &list);

    bool result = false;
    for (int i = 0 ; i < list.count ; ++i) {
        if (list.allergens[i] == gen) {
            result = true;
            break;
        }
    }

    free(list.allergens);
    return result;
}

void get_allergens(int score, Allergen_List_t* list) {
    list->count = 0;
    list->allergens = malloc(sizeof(Allergen_t) * 9);

    if (score >= 256)
        score -= ((int)pow(2, ceil(log(258)/log(2))))/2;

    if (score >= 128) {
        list->allergens[list->count++] = Allergen_Cats;
        score -= 128;
    }

    if (score >= 64) {
        list->allergens[list->count++] = Allergen_Pollen;
        score -= 64;
    }

    if (score >= 32) {
        list->allergens[list->count++] = Allergen_Chocolate;
        score -= 32;
    }

    if (score >= 16) {
        list->allergens[list->count++] = Allergen_Tomatoes;
        score -= 16;
    }

    if (score >= 8) {
        list->allergens[list->count++] = Allergen_Strawberries;
        score -= 8;
    }

    if (score >= 4) {
        list->allergens[list->count++] = Allergen_Shellfish;
        score -= 4;
    }

    if (score >= 2) {
        list->allergens[list->count++] = Allergen_Peanuts;
        score -= 2;
    }

    if (score >= 1)
        list->allergens[list->count++] = Allergen_Eggs;
}
