//
// Created by Vigo Wong on 28/4/20.
//
#include<iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend <= INT_MIN && divisor == -1) || (dividend >= INT_MAX && divisor == 1))
            return INT_MAX;
        if (dividend == 0) return 0;
        bool sign = bool(dividend < 0) == bool(divisor < 0);
        long long dividendABS = labs(dividend);
        long long divisorABS = labs(divisor);
        int ret = 0;
        while (divisorABS <= dividendABS) {
            int temp = 1;
            long long cur = divisorABS;
            while ((cur << 1) <= dividendABS) {
                cur <<= 1;
                temp <<= 1;
            }
            dividendABS -= cur;
            ret += temp;
        }
        return sign ? ret : -ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution c = Solution();
    cout << c.divide(10, 3);
    return 0;
}
