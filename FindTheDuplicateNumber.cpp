#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
	int res;
	for(int i=0; i<nums.size(); i++){
	    int n = nums[i];
	    if(n < 0)
		n = -n;
	    if(nums[n] > 0)
		nums[n] = -nums[n];
	    else{
		res = n;
		break;
	    }
	}

	for(int i=0; i<nums.size(); i++){
	    if(nums[i] < 0)
		nums[i] = -nums[i];
	}
	return res;
    }
};

int main(int argc, char *argv[]){
    vector<int> v{1, 3, 4, 2, 2};
    Solution sol;
    cout << sol.findDuplicate(v);
    return 0;
}
