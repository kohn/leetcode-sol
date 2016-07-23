class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int start = 0, end = 0;
        int min_size = 0;
        for(; end<nums.size(); end++){
            sum += nums[end];
            if(sum >= s)
                break;
        }
        if(end == nums.size())
            return 0;
        else
            min_size = end-start+1;
        while(start<=end){
            if(min_size == 1)
                return 1;
            if(sum > s){
                sum -= nums[start];
                start++;
            } else {
                end++;
                if(end == nums.size())
                    break;
                sum += nums[end];
            }
            if(sum >= s && end-start+1 < min_size)
                min_size = end-start+1;
        }
        return min_size;
    }
};


/**
 * 网上找的一种更为优雅的实现
 * 每次外循环中都保证sum<s
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) { 
            sum += nums[i]; 
            while (sum >= s) {
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
