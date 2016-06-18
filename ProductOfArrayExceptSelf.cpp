// T=O(n) S=O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size());
        int product = 1;
        for(int i=0; i<nums.size(); i++){
            ret[i] = product;
            product *= nums[i];
        }
        product = 1;
        for(int i=nums.size()-1; i>=0; i--){
            ret[i] = ret[i] * product;
            product *= nums[i];
        }
        return ret;
    }
};

// T=O(n) S=O(n)
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> ret(nums.size());
//         vector<int> right(nums.size());
//         vector<int> left(nums.size());
        
//         right[0] = nums[0];
//         left[nums.size()-1] = nums[nums.size()-1];
//         for(int i=1; i<nums.size(); i++){
//             right[i] = right[i-1]*nums[i];
//             left[nums.size()-i-1] = left[nums.size()-i]*nums[nums.size()-i-1];
//         }
        
//         ret[0] = left[1];
//         ret[nums.size()-1] = right[nums.size()-2];
//         for(int i=1; i<nums.size()-1; i++){
//             ret[i] = right[i-1] * left[i+1];
//         }
//         return ret;
//     }
// };

