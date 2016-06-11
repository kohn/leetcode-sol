class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0)
            return false;
        unordered_map<int, int> hashtable;
        for(int i=0; i<nums.size(); i++){
            if(hashtable.find(nums[i]) != hashtable.end()){
                int last_index = hashtable[nums[i]];
                if(i-last_index <= k)
                    return true;
                else
                    hashtable[nums[i]] = i;
            } else{
                hashtable[nums[i]] = i;
            }
        }
        return false;
    }
};
