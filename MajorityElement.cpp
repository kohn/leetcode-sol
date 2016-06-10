// // A More Elegent Way
// int majorityElement(vector<int>& nums) 
// {
//     int count = 0;
//     int candidate = nums[0];
//     for(int num : nums)
//     {
//         if(count == 0)
//             candidate = num;

//         if(num == candidate)
//             ++count;
//         else
//             --count;
//     }
//     // since "majority element always exist in the array" there is no need to verify candidate
//     return candidate;
// }

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
