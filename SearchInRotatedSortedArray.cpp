#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
	int size = nums.size();
	int left_bound = 0;
	int right_bound = size-1;
	int pos = size/2;

	if(target < nums[0]){	// target is located in right half
	    while(1){
		if(right_bound - left_bound < 10){
		    for(int i=left_bound; i<=right_bound; i++){
			if(nums[i] == target)
			    return i;
		    }
		    return -1;
		}
		
		if(nums[pos] <  target){
		    left_bound = pos;
		    pos = left_bound + (right_bound-left_bound)/2;
		} else if(nums[pos] > target){
		    if(nums[pos] < nums[0]){
			right_bound = pos;
			pos = left_bound + (right_bound - left_bound)/2;
		    } else{
			left_bound = pos;
			pos = left_bound + (right_bound-left_bound)/2;
		    }
		} else{
		    return pos;
		}
	    }
	} else if(target > nums[0]){
	    while(1){
		if(right_bound - left_bound < 10){
		    for(int i=left_bound; i<=right_bound; i++){
			if(nums[i] == target)
			    return i;
		    }
		    return -1;
		}
		
		if(nums[pos] > target){
		    right_bound = pos;
		    pos = left_bound + (right_bound-left_bound)/2;
		} else if(nums[pos] < target){
		    if(nums[pos] < nums[0]){
			right_bound = pos;
			pos = left_bound + (right_bound - left_bound)/2;
		    } else{
			left_bound = pos;
			pos = left_bound + (right_bound-left_bound)/2;
		    }
		} else{
		    return pos;
		}
	    }
	} else{
	    return 0;
	}
    }
};

int main(int argc, char *argv[]){
    Solution sol;
    vector<int> nums {4,5,6,7,0,1,2};
    cout << sol.search(nums, 3) << endl;
    return 0;
}
