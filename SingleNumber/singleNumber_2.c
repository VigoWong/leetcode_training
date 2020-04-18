//
// Created by Vigo Wong on 18/4/20.
//

#include "stdio.h"
#include "stdbool.h"

int findPos_1(unsigned char merge_num) {
    int count = 0;
    while (1) {
        if (merge_num >> count++ == 1)break;
    }
    return count;
}

bool ifPosSet(int num, int pos) {
    return ((num & pos) == 0);
}


void FindNumsAppearOnce(int *arr, int len, int *num1, int *num2) {
    int merge_num = 0;
    for (int i = 0; i < len; i++) {
        merge_num ^= arr[i];
    }
    int pos_critierial = findPos_1(merge_num);

    *num1 = 0;
    *num2 = 0;
    for (int i = 0; i < len; i++) {
        if (ifPosSet(pos_critierial, arr[i])) {
            *num1 ^= arr[i];
        } else {
            *num2 ^= arr[i];
        }
    }

}

int main(int argc, char const *argv[]) {
    int arr[] = {2, 4, 3, 6, 3, 2, 5, 5};
    int a = 0;
    int b = 0;
    FindNumsAppearOnce(arr, 8, &a, &b);
    printf("%d %d", a, b);
    return 0;
}
