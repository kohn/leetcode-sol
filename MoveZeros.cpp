class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int put_pos = 0;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(nums[i] != 0){
                if(put_pos != i){
                    nums[put_pos] = nums[i];
                }
                put_pos++;
            }
        }
        while(put_pos<size){
            nums[put_pos++] = 0;
        }
    }
};

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
