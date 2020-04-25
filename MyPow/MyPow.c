//
// Created by Vigo Wong on 25/4/20.
//
#include "stdio.h"
#include "stdlib.h"

double myPow(double x, int n) {
    if (n == 0) return 1;
    else {
        double temp = myPow(x, n / 2);
        if (n % 2 == 0) return temp * temp;
        else if(n > 0) return temp * temp * x;
        else return temp * temp / x;
    }

}


int main(int argc, char const *argv[]) {
    printf("%f\n", myPow(2.00000, -2));
    return 0;
}

