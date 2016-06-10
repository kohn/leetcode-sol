class Solution {
    
public:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void moveZeroes(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[j] != 0){
                        swap(nums, i, j);
                        break;
                    }
                }
            }
        }
    }
};
