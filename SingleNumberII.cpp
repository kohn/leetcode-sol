class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; i++){
            int mask = 1 << i;
            int count = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j] & mask)
                    count++;
            }
            if(count%3)		// 如果每个数重复n次, 这里count%n就可以. 于是可以解决任意重复次数的问题.
                res |= mask;
        }
        return res;
    }
};
