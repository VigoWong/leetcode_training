//
// Created by Vigo Wong on 28/5/20.
//

#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void operation(string op, stack<int> &s) {
        int sec = s.top();
        s.pop();
        int fir = s.top();
        s.pop();
        if(op == "+"){
            s.push(sec + fir);
        }
        else if(op == "-"){
            s.push(fir - sec);
        }
        else if(op == "*"){
            s.push(fir * sec);
        }
        else if(op == "/"){
            s.push(fir / sec);
        }
    }


    int evalRPN(vector<string> &tokens) {
        int pos = 0;
        stack<int> s;
        while (pos < tokens.size()) {
            if (isalnum(tokens[pos][0])||(tokens[pos].size()>1 && tokens[pos][0] == '-')) {
                s.push(atoi(tokens[pos].c_str()));
            }else{
                operation(tokens[pos], s);
            }
            pos++;
        }
        return s.top();
    }
};


int main(int argc, char const *argv[]){
    Solution a  =Solution();
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << a.evalRPN(tokens);
    return 0;
}