#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	if(nums.size() == 0)
	    return;

	for(vector<int>::reverse_iterator iter = nums.rbegin();
	    iter != nums.rend();
	    iter++){

	    if(iter == nums.rbegin())
		continue;

	    vector<int>::reverse_iterator min = nums.rend();
	    for(vector<int>::reverse_iterator it = iter-1;;it--){
		if(*it > *iter){
		    if(min == nums.rend() || *it < *min)
			min = it;
		}

		if(it == nums.rbegin())
		    break;
	    }
	    if(min != nums.rend()){
		int tmp = *min;
		*min = *iter;
		*iter = tmp;
		sort(nums.rbegin(), iter, std::greater<int>());
		return;
	    }
	}
	sort(nums.rbegin(), nums.rend(), std::greater<int>());
    }
};

int main(int argc, char *argv[]){
    Solution sol;
    {
	vector<int> nums{4,2,0,2,3,2,0};
	sol.nextPermutation(nums);
	for(auto a: nums){
	    cout << a << " ";
	}
    }
    cout << endl;
    {
	vector<int> nums{1, 3, 2};
	sol.nextPermutation(nums);
	for(auto a: nums){
	    cout << a << " ";
	}
    }

    return 0;
}
