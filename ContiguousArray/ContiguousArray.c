//
// Created by Vigo Wong on 22/4/20.
//
#include "stdio.h"
#include "../data_structure/uthash/include/uthash.h"

typedef struct hashset {
    int key;
    int index;
    UT_hash_handle hh;
} *hash;

int findMaxLength(int *nums, int numsSize) {
    int sum = 0;
    int max_len = 0;
    hash h = NULL;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            nums[i] = -1;
        } else continue;
    }

    for (int i = 0; i < numsSize; i++) {
        hash cur = NULL;
        sum += nums[i];
        HASH_FIND_INT(h, &sum, cur);
        if (cur != NULL) {
            int diff = i - (cur->index);
            if (diff > max_len) max_len = diff;
        } else {
            cur = malloc(sizeof(struct hashset));
            cur->key = sum;
            cur->index = i;
            HASH_ADD_INT(h, key, cur);
        }
    }
    return max_len;
}


int main(int argc, char const *argv[]){
    int arr[] = {0,1,0,0,0,1,1};
    printf("%d", findMaxLength(arr, 7));
    return 0;
}
