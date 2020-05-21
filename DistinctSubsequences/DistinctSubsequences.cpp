//
// Created by Vigo Wong on 21/5/20.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        vector<vector<int>> arr(tSize+1, vector<int> (sSize+1));
        for(int i = 0 ; i < sSize+1; i ++){
            arr[0][i] = 1;
        }
        for(int i = 1 ; i< tSize+1; i++){
            arr[i][0] = 0;
        }
        for(int i = 1 ; i<tSize+1; i++){
            for(int j = 1; j < sSize+1; j++){
                if(s[j-1] == t[i-1]){
                    arr[i][j] = arr[i-1][j-1]+arr[i][j-1];
                }else{
                    arr[i][j] = arr[i][j-1];
                }
            }
        }
        return arr[tSize][sSize];
    }
};


int main(int argc, char const *argv[]){
    string S = "rabbbit", T = "rabbit";
    Solution a = Solution();
    cout << a.numDistinct(S, T);
    return 0;
}