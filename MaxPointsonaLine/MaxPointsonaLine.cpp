//
// Created by Vigo Wong on 28/5/20.
//
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    pair<float, float> get_k_and_b(vector<int> p1, vector<int> p2) {
        // y = kx + b
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        float dx = x2 - x1;
        float dy = y2 - y1;
        if (dx == 0)
            return pair<float, float>(0, 0);
        else {
            float k = dy / dx;
            float b = y1 - k * x1;
            return pair<float, float>(k, b);
        }

    }

    int maxPoints(vector<vector<int>> &points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            map<pair<float, float>, int> a;
            int dup = 1;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    dup++;
                    continue;
                } else {
                    ++a[{get_k_and_b(points[i], points[j])}];
                }
            }
            res = max(res, dup);
            for (auto it = a.begin(); it != a.end(); ++it) {
                res = max(res, it->second + dup);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution a = Solution();
    vector<vector<int>> ps = {{1, 1},
                              {3, 2},
                              {5, 3},
                              {4, 1},
                              {2, 3},
                              {1, 4}};
    cout << a.maxPoints(ps);
    return 0;
}