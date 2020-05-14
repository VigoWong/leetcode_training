//
// Created by Vigo Wong on 13/5/20.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return a > b ? b : a;
    } q

    int largestRectangleArea(vector<int> &heights) {
//        int start = 0;
//        int maxRec = 0;
//        int end = 0;
//        int curMin = 0;
//        int curMax = 0;
//        int width;
//
//        vector<int> curLS;
//        while (start < heights.size()) {
//            if(start == heights.size()-1){
//                if (maxRec < heights[start]) maxRec = heights[start];
//            }
//            width = 1;
//            end = start + 1;
//            curLS.push_back(heights[start]);
//            while (end < heights.size()) {
//                width++;
//                curMin = min(*min_element(curLS.begin(), curLS.end()), heights[end]);
//                curMax = max(*max_element(curLS.begin(), curLS.end()), heights[end]);
//                curLS.push_back(heights[end]);
//                if (maxRec < curMin * width) maxRec = curMin * width;
//                end++;
//            }
//
//            curLS.clear();
//            start++;
//        }
//        return maxRec;
//    }
        int res = 0;
        stack <int> s;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            if(s.empty() || heights[i] >= heights[s.top()]){
                s.push(i);
            }else{
                int curPos = s.top();
                s.pop();
                int curh = heights[curPos];
                res = max(res, curh * (s.empty()? i : (i - 1 - s.top())));
                --i;
            }
        }
        return res;
    }

};

int main(int argc, char const *argv[]){
    Solution s = Solution();
    vector<int> ls= {2,1,5,5,4,3};
    cout << s.largestRectangleArea(ls);
    return 0;
}