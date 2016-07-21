class Solution {
public:
    int sign(int num){
        if(num < 0)
            return -1;
        if(num > 0)
            return 1;
        return 0;
    }
    
    int findNext(vector<int> &nums, int s, int start_pos){
        int ret_pos = start_pos;
        while(ret_pos+1 < nums.size()){
            if(sign(nums[ret_pos+1]-nums[ret_pos]) == -s)
                break;
            ret_pos++;
        }
        return ret_pos;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0 || nums.size()==1)
            return nums.size();
        int last_sign = sign(nums[1]-nums[0]);
        int pos = 1;
        while(last_sign == 0 && pos<nums.size()){
            pos++;
            last_sign = sign(nums[pos]-nums[0]);
        }
        if(pos == nums.size())
            return 1;
        pos = findNext(nums, last_sign, pos);
        int max_length = 1;
        while(pos < nums.size()){
            last_sign = -last_sign;
            pos = findNext(nums, last_sign, pos+1);
            max_length++;
        }
        return max_length;
    }
};
