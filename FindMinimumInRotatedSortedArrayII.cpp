#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int find_linear(vector<int>&nums, int left_bound, int right_bound){
	int min = nums[left_bound];
	for(int i=left_bound+1; i<=right_bound; i++)
	    if(nums[i] < min)
		min = nums[i];
	return min;
    }
    int findMin(vector<int>& nums) {
        int left_bound = 0;
	int right_bound = nums.size()-1;

	if(nums[0] == nums[nums.size()-1]){
	    int lb = left_bound;
	    int rb = right_bound;
	    while(lb < rb && nums[lb] == nums[0] && nums[rb] == nums[0]){ // 退化为O(N)了竟然也能ac
		lb++;
		rb--;
	    }
	    if(lb == rb){
		return nums[0]>nums[lb]?nums[lb]:nums[0];
	    } else if(lb > rb){
		return nums[0];
	    } else{
		left_bound = lb;
		right_bound = rb;
	    } 
	}
	
	while(right_bound - left_bound > 5){
	    int bound = left_bound + (right_bound-left_bound)/2;
	    int mid = nums[bound];
	    if(mid  <= nums[right_bound]){
		right_bound = bound;
	    } else if(mid >= nums[left_bound]){
		left_bound = bound;
	    } 
	}
	int min = find_linear(nums, left_bound, right_bound);
	return min>nums[0]?nums[0]:min;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums{3, 1};
    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}
