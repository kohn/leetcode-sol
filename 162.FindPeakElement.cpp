class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int left = INT_MIN;
            int right = INT_MIN;
            if(mid > 0)
                left = nums[mid-1];
            if(mid < nums.size()-1)
                right = nums[mid+1];
            if(nums[mid]> left && nums[mid]>right)
                return mid;
            else if(nums[mid] < left)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return 0;
    }
};
