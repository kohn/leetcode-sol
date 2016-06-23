class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i] < 0){
                sum = 0;
            } else{
                sum += nums[i];
                if(sum > max)
                    max = sum;
            }
        }
        if(sum > max)
            max = sum;
        if(max == 0){
            max = INT_MIN;
            for(int n:nums)
                if(n>max)
                    max = n;
        }
        return max;
    }
};
