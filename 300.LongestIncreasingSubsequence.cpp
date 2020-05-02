class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int maxLength = 0;
    // 设length[i]为以i为起点, 到数字列表最后这一段, 最长的字串
    // length[i] = max(length[j]+1) for j in (i, nums.size()) and nums[i]<nums[j]
    vector<int> length(nums.size(), 1);
    for (int i=nums.size()-1; i>=0; i--) {
      // 这一步其实是在找length[i:]中最大的那个值
      for (int j=i; j<nums.size(); j++) {
        if(nums[i] < nums[j]) {
          length[i] = max(length[i], length[j]+1);
        }
      }
      if(length[i] > maxLength) {
        maxLength = length[i];
      }
    }
    return maxLength;
  }
};

/* o(nlgn)的方法:
 * https://leetcode.com/problems/longest-increasing-subsequence/discuss/577772/O(n*log(n))-Solution!-Using-Binary-Search!
 * 维护一个叫做dp的列表, 里面的值是最可能成为最长字串的一个串
 * 每次遍历一个新的数字ar[i], 找到数组里刚刚好比他大一点的那个数字dp[k], dp[k]=ar[i]
 * 如果ar[i] > dp[length], 说明找到了一个新的字串比之前找到的都打, dp[++length] = ar[i]
 */
class Solution {
public:
  int ceilindex(int *dp,int si,int ei,int key)
  {
    if(si>=ei) return si;
    int mid = (si+ei)/2;
    if(dp[mid]>=key) return ceilindex(dp,si,mid,key);
    else return ceilindex(dp,mid+1,ei,key);
  }
  int lengthOfLIS(vector<int>& ar) {
    int n = ar.size();
    if(n==0) return 0;
    else
      {
        int dp[n];
        dp[0] = ar[0];
        int length = 0;
        for(int i=1;i<n;i++)
          {
            if(ar[i]<dp[0]) dp[0] = ar[i];
            else if(ar[i]>dp[length]) dp[++length] = ar[i];
            else
              dp[ceilindex(dp,0,length,ar[i])] = ar[i];
          }
        return length+1;
      }
  }
};

