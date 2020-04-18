//
// Created by Vigo Wong on 18/4/20.
//
#include "stdio.h"
#include "stdbool.h"


bool isHappy(int n){
    int sum = 0;
    while (n != 1 && n != 4){   
        while (n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        n = sum;
        sum = 0;
    }
    return (n == 4);
}



