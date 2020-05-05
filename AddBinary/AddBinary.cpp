//
// Created by Vigo Wong on 5/5/20.
//
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:


    string addBinary(string a, string b) {
        int sumA = 0;
        int sumB = 0;
        int cur = a.size() -1;
        int power = 0;
        while(cur >= 0){
            if(a[cur] == '1'){
                sumA += pow(2, power);
            }
            cur --;
            power++;
        }
        cur = b.size() -1;
        power = 0;
        while(cur >= 0){
            if(b[cur] == '1'){
                sumB += pow(2, power);
            }
            cur --;
            power++;
        }
        int s = sumA + sumB;
        string ret = "";
        while (s!=0){
            if(s%2 == 0)
                ret = "0" + ret;
            else ret = "1" + ret;
            s /= 2;
        }
        return ret;
    }
};

int main(int argc, char const *argv[]){
    Solution s = Solution();
    cout << s.addBinary("1010", "1011");
    return 0;
}

