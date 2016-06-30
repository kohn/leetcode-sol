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
    void swap(vector<int> &v, int i, int j){
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
    }
    void permute(vector<vector<int>> &permutations, int num){
	int origin_size = permutations.size();
	for(int j=0; j<origin_size; j++){
	    vector<int> *p = &permutations[j];
	    p->push_back(num);
	    int size = p->size();
	    for(int i=0; i<size-1; i++){
		swap(*p, i, size-1);
		permutations.push_back(*p);
		p = &permutations[j];
		swap(*p, size-1, i);
	    }
	}
    }
    vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ret;
	if(nums.size() == 0)
	    return ret;
	ret.push_back(vector<int>(1, nums[0]));
	for(int i=1; i<nums.size(); i++)
	    permute(ret, nums[i]);
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
    vector<int> nums={1,2,3,4,5};
    auto v = sol.permute(nums);
    print(v);
    return 0;
}
