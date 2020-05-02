class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        permutate(results, nums, 0);
        return results;
    }

    void permutate(vector<vector<int>> &results, vector<int> &nums, int start) {
        if (start == nums.size()) {
            results.push_back(nums);
            return;
        }

        map<int, bool> appeared;
        for (int i=start; i<nums.size(); i++) {
            if (appeared.find(nums[i]) != appeared.end()) {
                continue;
            }
            appeared[nums[i]] = true;
            swap(nums[start], nums[i]);
            permutate(results, nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
};


class Solution2 {
public:
  vector<vector<int>> res;
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    generate(0,nums);
    return res;
  }

  // 注意这里nums不是引用传值, 而是直接复制了一份新的vector, 这样就不会在深层的遍历中打乱顺序
  // 所有swap(nums[i], nums[k])之后, 不用swap回来.
  // 同时, 由于i=0时, nums是有序的, 且深层次的遍历不会打乱nums[i+1:]的顺序, 因此
  //  if( i != k && nums[i] == nums[k])continue这句能保证nums右边始终是有序的.
  void generate(int i, vector<int> nums) {
    if(i == nums.size() - 1) {
      res.push_back(nums);
      return;
    }
    for(int k = i;k<nums.size();k++) {
      if( i != k && nums[i] == nums[k])
        continue;
      swap(nums[i],nums[k]);
      generate(i + 1, nums);
    }
  }
};
