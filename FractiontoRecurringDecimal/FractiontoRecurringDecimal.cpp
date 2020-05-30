//
// Created by Vigo Wong on 30/5/20.
//

#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> m;
		string before = "",end = "";
        if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) before ="-";
		int i = 0;
		long long a = abs((long long)numerator), b = abs((long long)denominator),r;
		r = a % b;
		before += to_string(a / b);
		if (!r) return before;
		a = r * 10;
		while (!m.count(a))
		{
			m[a] = i;
			r = a % b;
			end += to_string(a / b);
			if (!r) return before + "." + end;;
			a = r * 10;
            i++;
		}
		int c = m[a];
		end.insert(end.begin(),'(');
		return before + "." + end + ")";

    }
};

int main(int argc, char const *argv[]){
    Solution a = Solution();
    string s = a.fractionToDecimal(2,7);
    cout << s;
    return 0;
}