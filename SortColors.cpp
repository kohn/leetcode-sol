class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red_count = 0;
        int blue_count = 0;
        int white_count = 0;
        for(int n : nums){
            if(n == 0)
                red_count++;
            if(n == 1)
                white_count++;
            if(n == 2)
                blue_count++;
        }
        
        int pos = 0;
        for(int i=0; i<red_count; i++)
            nums[i+pos] = 0;
        pos += red_count;
        for(int i=0; i<white_count; i++)
            nums[i+pos] = 1;
        pos += white_count;
        for(int i=0; i<blue_count; i++)
            nums[i+pos] = 2;
    }
};
