//
// Created by Vigo Wong on 19/4/20.
//


#include "stdio.h"
#include "stdlib.h"
#include "../data_structure/uthash/include/uthash.h"

typedef struct hash {
    int key;
    int count;
    UT_hash_handle hh;
} hash, *hash_p;

int countElements(int *arr, int arrSize) {
    hash_p table = NULL;
    for (int i = 0; i < arrSize; i++) {
        hash_p h = NULL;
        HASH_FIND_INT(table, &arr[i], h);

        if (h == NULL) {
            h = malloc(sizeof(hash));
            h->key = arr[i];
            h->count = 1;
            HASH_ADD_INT(table, key, h);
        } else {
            h->count++;
        }
    }
    hash_p k;
    int totalCount = 0;
    for (int i = 0; i < arrSize; i++) {
        int val = arr[i] + 1;
        HASH_FIND_INT(table, &val, k);
        if (k) totalCount += 1;
    }
    return totalCount;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 3, 2, 3, 5, 0};
    printf("%d", countElements(arr, 6));
    return 0;
}