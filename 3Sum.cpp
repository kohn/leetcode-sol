#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <assert.h>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() < 3)	// std::sort貌似要求至少两个元素， 否则会出错
            return ret;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1; j<nums.size()-1; j++){
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                int sum = nums[i] + nums[j];
                for(int k = nums.size()-1; k>j; k--){
                    if(k<nums.size()-1 && nums[k] == nums[k+1])
                        continue;
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        ret.push_back(tmp);
                    } else if(sum < 0){
                        break;
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> vec{-1, 0, 1, 2, -1, -4};
    vector<int> a{0, 1};
    vector<vector<int> > ans = sol.threeSum(a);
    for(auto &i : ans){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}
