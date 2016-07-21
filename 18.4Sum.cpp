#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void print(vector<int> &v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
}

void print(vector<vector<int>> &v){
    for(auto &i:v){
	print(i);
    }
}

class Solution {
public:
    vector<vector<int>> NSum(vector<int>& nums, int target, int n, int start){
        vector<vector<int>> ret;
        if(n == 1){
            for(int i=start; i<nums.size(); i++)
                if(nums[i] == target){
                    ret.push_back(vector<int>(1, target));
                    break;
                }
        } else{
            for(int i=start; i+n-1<nums.size(); i++){
                if(i>start&&nums[i-1]==nums[i]) continue;
                int sum = 0;
                for(int j=0; j<n; j++){
                    sum += nums[i+j];
                }
                if(sum>target)
                    break;
                sum = nums[i];
                for(int j=1; j<n; j++){
                    sum += nums[nums.size()-j];
                }
                if(sum < target)
                    continue;
                vector<vector<int>> tmp = NSum(nums, target-nums[i], n-1, i+1);
                for(int j=0; j<tmp.size(); j++){
                    tmp[j].push_back(nums[i]);
                    ret.push_back(tmp[j]);
                }
            }
        }
        return ret;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return NSum(nums, target, 4, 0);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> input{1,0,-1,0,-2,2};
    vector<int> input2{-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> result = sol.fourSum(input2, 0);
    print(result);
    return 0;
}
