//
// Created by Vigo Wong on 26/4/20.
//
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int charToInt(char c) {
    char a = 0;
    return (c - a);
}


char *multiply(char *num1, char *num2) {
    int* sum = (int*)calloc(220, sizeof(int));
    if(num1 == NULL || num2 == NULL || num1[0] == '0' || num2[0] == '0') {
        char* result = (char*)calloc(2, sizeof(char));
        result[0] = '0';
        return result;
    }
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int i = 0, j = 0, t = 0, index = 0;
    for(i = 0; i < l1; i++) {
        for(j = 0; j < l2; j++) {
            sum[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for(i = l1 + l2 - 2; i >= 0; i--) {
        sum[i] += t;
        if(sum[i] >= 10) {
            t = sum[i] / 10;
            sum[i] = sum[i] % 10;
        }
        else
            t = 0;
    }
    int len = 2 + (t ? l1 + l2 - 1 : l1 + l2 - 2);
    char* result = (char*)malloc(len * sizeof(char));
    if(t)
        result[index++] = '0' + t;
    for(i = 0; i <= l1 + l2 - 2; i++)
        result[index++] = sum[i] + '0';
    result[index] = 0;
    free(sum);
    return result;
}


int main(int argc, char const *argv[]) {
    char num1[] = "123";
    char num2[] = "456";
    printf("%s" , multiply(num1, num2));
    return 0;
}