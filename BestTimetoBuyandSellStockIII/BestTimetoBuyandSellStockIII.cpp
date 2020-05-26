//
// Created by Vigo Wong on 22/5/20.
//
#include<queue>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        priority_queue<int> q;
        int p = 0;
        while (p < prices.size() - 1) {
            if (prices[p] <= prices[p + 1]) {
                int start = prices[p];
                p++;
                while (p != prices.size() - 1 && prices[p] < prices[p + 1]) {
                    p++;
                }
                int gap = prices[p] - start;
                q.push(gap);
            } else {
                p++;
            }
        }
        int first;
        int sed;
        if(q.size()>=2){
            int first = q.top(); q.pop();
            int sed = q.top();
            return first+sed;
        }else if(q.size()==1){
            sed = 0;
            first = q.top();
            return first;
        }else{
            return 0;
        }
    }
};

int main(int argc, char const *argv[]){
    vector<int> v = {7,6,4,3,1};
    Solution a = Solution();
    cout << a.maxProfit(v);
    return 0;
}