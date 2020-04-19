//
// Created by Vigo Wong on 19/4/20.
//

#include "BestTimeToBuyAndSellStock.h"
#include "stdio.h"


int maxProfit(int *prices, int pricesSize) {
    int start = prices[0];
    int last = prices[0];
    int diff = 0;
    int sum = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (last <= prices[i] && i != pricesSize - 1) {
            diff = prices[i] - start;
            last = prices[i];
        } else {
            sum += diff;
            diff = 0;
            last = prices[i];
            start = prices[i];
        }
    }
    return sum;
}


int main(int argc, char const *argv[]) {
    int arr[] = {7, 6, 4, 3, 1};
    printf("%d", maxProfit(arr, 6));
    return 0;
}
