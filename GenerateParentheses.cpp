#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    void put(vector<char> &sta, int left, int right, vector<string> &ret){
	if(left > 0){
	    sta.push_back('(');
	    put(sta, left-1, right, ret);
	}

	if(right>0 and left < right){
	    sta.push_back(')');
	    put(sta, left, right-1, ret);
	}

	if(left == 0 && right == 0){
	    string str;
	    for(auto c:sta){
		str.push_back(c);
	    }
	    ret.push_back(str);
	}
	sta.pop_back();
    }
    vector<string> generateParenthesis(int n) {
	vector<string> ret;
	vector<char> sta;
	sta.push_back('(');
	put(sta, n-1, n, ret);
	return ret;
    }
};

int main(int argc, char *argv[]){
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    cout << res.size() << endl;
    for(auto &s:res){
	cout << s << endl;
    }
    return 0;
}
