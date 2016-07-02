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

class Solution {
public:
    void insert(vector<vector<int>> &ret, int n){
	int size = ret.size();
	for(int i=0; i<size; i++){
	    vector<int> v = ret[i];
	    v.push_back(n);
	    ret.push_back(v);
	}
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>{});
        for(int n : nums){
            insert(ret, n);
        }
        return ret;
    }
};

void print(vector<vector<int>> &v){
    for(auto &i:v){
	print(i);
    }
}

int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> nums={3,2,4,1};
    auto v = sol.subsets(nums);
    print(v);
    return 0;
}
