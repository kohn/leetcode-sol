#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void print(vector<int> &v){
    for(auto i:v){
	cout << i << " ";
    }
    cout << endl;
}

void print(vector<vector<int>> &v){
    for(auto &i:v){
	print(i);
    }
}

class Solution {
public:
    void combinationSum3(vector<vector<int>> &ret, int k, int n, int start){
	if(k <= 0)
	    return;
        if(k == 1){	    
            if(n<=9 && n>start){
		vector<int> tmp;
                tmp.push_back(n);
		ret.push_back(tmp);
	    }
        } else if(k == n && start == 0 && n==1){
	    vector<int> tmp;
	    tmp.push_back(1);
            ret.push_back(tmp);
        } else if(k>n){
            ;
        } else{
            for(int i=start+1; i<=9; i++){
                vector<vector<int>> tmp;
                combinationSum3(tmp, k-1, n-i, i);
                for(vector<int> &v : tmp){
                    v.push_back(i);
                    ret.push_back(v);
                }
            }   
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        combinationSum3(ret, k, n, 0);
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<vector<int>> ret = sol.combinationSum3(3, 9);
    print(ret);
    return 0;
}
