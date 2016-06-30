class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        if(nums[hi] >= nums[lo])
            return nums[lo];
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>=nums[0])
                lo = mid+1;
            else if(nums[mid] < nums[0])
                hi = mid;
        }
        return nums[lo];
    }
};
