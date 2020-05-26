//
// Created by Vigo Wong on 24/5/20.
//

#include <algorithm>
#include <vector>
#include <iostream>

// Definition for a Node.
using namespace std;

class Solution {
public:
    bool canReach(int src, int location, int gasLeft, vector<int> &gas, vector<int> &cost) {
        if (gasLeft < 0) return false;
        if (src == location)return true;
        return canReach(src, location==gas.size()-1?0:location+1,  gasLeft - (cost[location]-gas[location]),
                gas, cost);
    }


    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        for (int i = 0; i < gas.size(); i++) {
            if (cost[i] <= gas[i] && canReach(i, i == gas.size() - 1 ? 0 : i, gas[i] - cost[i], gas, cost))
                return i;
            else continue;
        }
        return -1;
    }
};



int main(int argc, char const *argv[]){
    vector<int> gas  = {2,3,4};
    vector<int> cost  = {3,4,3};
    Solution a = Solution();
    cout << a.canCompleteCircuit(gas, cost);

    return 0;
}