class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int n = nums[i]%(nums.size()+1);
            if(n != nums.size())
                nums[n] += (nums.size()+1)*2;
        }
        for(int i=0; i<nums.size(); i++)
            if(nums[i] <=nums.size())
                return i;
        return nums.size();
    }
};
