#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <bitset>
#include <map>
using namespace std;

class Solution {
private:
    int A[502][502];
public:

    void calculate(vector<int>& nums, int lo, int hi){
	int max = 0;
	for(int i=lo; i<=hi; i++){
	    int this_run = get(nums, lo, i-1)
		+ get(nums, i+1, hi)
		+ nums[i]*nums[lo-1]*nums[hi+1];

	    if(this_run > max)
		max = this_run;
	}
	cout << lo << ", " << hi << ": " << max << endl;
	A[lo][hi] = max;
    }

    int get(vector<int>& nums, int lo, int hi){
	if(lo > hi)
	    return 0;
	
	if(A[lo][hi] == -1)
	    calculate(nums, lo, hi);
	return A[lo][hi];
    }
    
    int maxCoins(vector<int>& nums) {
	if(nums.size() == 0)
	    return 0;
	
	memset(A, -1, sizeof(A));
	nums.insert(nums.begin(), 1);
	nums.push_back(1);

	return get(nums, 1, nums.size()-2);
    }
};

int main(int argc, char *argv[]){
    Solution sol;
    vector<int> nums{3, 1, 5, 8};
    cout << sol.maxCoins(nums) << endl;

    return 0;
}
