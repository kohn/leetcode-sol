class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size()<3) {
      return false;
    }
    vector<int> temp(3, 0);
    int length = 0;
    temp[0] = nums[0];
    for (int i=1; i<nums.size(); i++) {
      if(nums[i]>temp[length]) {
        temp[++length] = nums[i];
        if (length+1 == 3) {
          return true;
        }
        continue;
      }

      int maxSmallerIndex = length;
      for (;maxSmallerIndex >= 0; maxSmallerIndex--){
        if (temp[maxSmallerIndex] < nums[i]){
          break;
        }
      }
      temp[maxSmallerIndex+1] = nums[i];
    }
    return false;
  }
};
/*
 * 最优解:
 * https://leetcode.com/problems/increasing-triplet-subsequence/discuss/594995/C%2B%2Bor95-Runtime-(4ms)-or-100-Memoryor-O(n)-time-and-O(1)-space
 */

class Solution2 {
public:
  bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    if(n<3) return false;
    int least=INT_MAX, second_least=INT_MAX;
        
    for(int i=0; i<n; i++) {
      if(nums[i]>second_least) return true;
      if(nums[i]>least) second_least=nums[i];
      if(nums[i]<least) least=nums[i];
    }
    return false;
  }
};
