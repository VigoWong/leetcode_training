//
// Created by Vigo Wong on 24/5/20.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candynum(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                candynum[i] = candynum[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i + 1] < ratings[i] && candynum[i] >= candynum[i + 1]) {
                candynum[i] = candynum[i + 1] + 1;
            }
        }
        int ret = 0;
        for (int num : candynum) ret += num;
        return ret;
    }
};


int main(int argc, char const *argv[]) {
    vector<int> ratings = {1,2,2};
    Solution a = Solution();
    cout << a.candy(ratings);
    return 0;
}