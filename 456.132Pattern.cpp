class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        return find132(nums, 0);
    }
    
    bool checkSegment(vector<pair<int, int>> &segments, int num) {
        for (auto p : segments) {
            if(p.first< num && num < p.second) {
                return true;
            }
        }
        return false;
    }
    
    bool find132(vector<int> &nums, int start) {
        vector<pair<int, int>> segments;
        
        int order[2];
        int length = 0;
        for(int i=0; i<nums.size(); i++) {
            if(checkSegment(segments, nums[i])) {
                return true;
            }
            if(length == 0) {
                order[length++] = nums[i];  
                continue;
            }
            
            if(length == 1 && nums[i] < order[0]) {
                order[0] = nums[i];
                continue;
            }
            
            if(length == 1 && nums[i] > order[0]) {
                order[length++] = nums[i];
                continue;
            }
            
            if(length == 2 && nums[i] > order[1]) {
                order[1] = nums[i];
                continue;
            }
            
            if(length == 2 && nums[i] > order[0] && nums[i] < order[1]) {
                return true;
            }
            
            if(length == 2 && nums[i] < order[0]) {
                segments.push_back(make_pair(order[0], order[1]));
                order[0] = nums[i];
                length = 1;
            }
        }
        return false;
    }
};

/*
 *最优解:
 * https://leetcode.com/problems/132-pattern/discuss/554441/C%2B%2B-8-lines-O(n)-Stack-Solution-with-Explanation
 * 本质上是维护了一个堆栈, 以及一个s2. s2表示num[i+1:]中, 满足k<j且num[k]>num[j]的那个num[j]. 也就是说在s2这个数字左边, 必定有一个数字比s2大. 而且s2是满足这个条件的数字中, 最大的那一个.
 * 只要再在遍历过程中找到一个数字小于s2, 就能说明满足132模式.
 * 堆栈有两个特性:
 *   1. 堆栈里的数字则是处于有序状态, 越深的数越大.
 *   2. 堆栈里的所有数字都大于s2
 * 
 * 当遍历num[i]时, 如果num[i] < s2, 说明找到了132. 直接返回
 * 如果num[i] > s2, 此时需要找到新的s2, 就可以从堆栈中不断pod, 直到栈顶的数字>num[i], pop出来的数字必然是小于
 * num[i]的, 且越里面的数字越大, 到pop不出来时, 上一个pop出来的数字就是比num[i]小的最大数, 就是新的s2. 如果一个
 * 都pop不出来, 说明老的s2就是那个小于num[i]的最大数
 *
 *
 * 从这道题的解法思路上扩展, 为了解决这种问题, 首先需要定义一个中间目标. 比如这道题就是: 从右到左遍历,
 * 找到一个数字s2, s2是num[i+1:]中的一个, 且满足条件: s2的左边必定有一个数大于s2. 这样每次遍历是只要做两件事,
 * 1. 判断当前数是不是小于s2. 2. 如果大于s2, 更新s2的值. 接下来就是看如何实现这个目标,
 * 这题的解法就是通过一个stack来维护.
 */
bool find132pattern(vector<int>& nums) { //O(n) Time & Space -> Stack
  if(nums.size() < 3) return false;
  stack<int> s3;
  int s2 = INT_MIN;
  for(int i=nums.size()-1; i>=0; i--) {
    if(nums[i] < s2) return true;
    else while(!s3.empty() && nums[i]>s3.top()) {
        s2 = s3.top(), s3.pop(); 
      }
    s3.push(nums[i]);
  }
  return false;
}

