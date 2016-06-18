class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        if(nums[hi] < target)
            return nums.size();
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target && target < nums[mid+1])
                return mid+1;
            if(nums[mid] < target)
                lo = mid+1;
            else 
                hi = mid-1;
        }
        return 0;
    }
};
