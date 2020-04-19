//
// Created by Vigo Wong on 19/4/20.
//


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../data_structure/uthash/include/uthash.h"


int compare(const void *a, const void *b) {
    return (*(char *) a) - (*(char *) b);
}


char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int *returnColumnSizes) {
    struct hashTable {
        int row;
        int col;
        char key[128];
        UT_hash_handle hh;
    };

    struct hashTable *table = NULL;
    char ***retLs = malloc(sizeof(char **) * strsSize);
    int row = 0;


    for (int i = 0; i < strsSize; i++) {
        struct hashTable *h = NULL;
        char cur_s[64] = "";
        strcpy(cur_s, strs[i]);
        qsort(cur_s, strlen(cur_s), sizeof(char), compare);

        HASH_FIND_STR(table, cur_s, h);

        if (!h) {
            h = malloc(sizeof(struct hashTable));
            strcpy(h->key, cur_s);
            h->row = row;
            h->col = 1;
            HASH_ADD_STR(table, key, h);

            retLs[row] = malloc(sizeof(char*) * strsSize);
            retLs[row][0] = malloc(sizeof(char) * 64);
            strcpy(retLs[row][0], strs[i]);

            row ++;
        }
        else {
            retLs[h->row][h ->col] = malloc(sizeof(char) * 64);
            strcpy(retLs[h->row][h ->col] , strs[i]);
            h ->col++;
        }
    }

    *returnSize = row;



    for (struct hashTable * s = table; s!= NULL; s = s->hh.next)
        returnColumnSizes[s->row] = s->col;

    return retLs;
}


int main(int argc, char const *argv[]){
    char str1[64] = "eat";
    char str2[64] = "tea";
    char str3[64] = "tan";
    char str4[64] = "ate";
    char str5[64] = "bat";
    char **str = malloc(sizeof(char*) * 5);
    str[0] = str1;
    str[1] = str2;
    str[2] = str3;
    str[3] = str4;
    str[4] = str5;
    char ***ret;
    int retS = 0;
    int col[5];
    ret = groupAnagrams(str, 5, &retS, col);
    for(int i=0; i<retS; i++){
        for(int j=0; j<col[i]; j++){
            printf("%s ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}

