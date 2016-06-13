class NumArray {
public:
    int *dp;
    NumArray(vector<int> &nums) {
        dp = new int[nums.size()];
        if(nums.size() == 0)
            return;
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = dp[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if(i == 0)
            return dp[j];
        else
            return dp[j]-dp[i-1];
    }
};
