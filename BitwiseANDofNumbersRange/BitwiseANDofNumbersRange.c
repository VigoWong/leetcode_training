//
// Created by Vigo Wong on 24/4/20.
//
#include "stdio.h"


int power2(int val){
    int count = 0;
    while (val != 0){
        count++;
        val/=2;
    }
    return count;
}



int rangeBitwiseAnd(int m, int n){
    int diff = n - m;
    int ret = m;
    if(diff > m) return 0;
    else{
        int pos = power2(diff);
        ret = (ret >> pos);
        ret = (ret << pos);
        return ret;
    }
//    int i = 0;
//    while (m != n){
//        m >>= 1;
//        n >>= 1;
//        i += 1;
//    }
//    return m << i;
}

int main(int argc, char const *argv[]){
    printf("%d", rangeBitwiseAnd(26, 30));
    return 0;
}



