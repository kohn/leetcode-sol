#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int left_bound(vector<int> &nums, int target, int index){
        int lo = 0;
        int hi = index;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        return lo;
    }
    int right_bound(vector<int> &nums, int target, int index){
        int lo = index;
        int hi = nums.size()-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target){
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        return hi;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> ret;
        if(nums.size() == 0)
            return ret;
        while(left < right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target){
                ret.push_back(left_bound(nums, target, mid));
                ret.push_back(right_bound(nums, target, mid));  
                return ret;
            } else if(nums[mid] < target){
                left = mid+1;
            } else{
                right = mid-1;
            }
        }
        if(nums[right] != target){
            ret.push_back(-1);
            ret.push_back(-1);

        } else{
            ret.push_back(left);
            ret.push_back(right);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> vec = {0,0,0,0,1,2,3,3,4,5,6,6,7,8,8,8,9,9,10,10,11,11};
    vector<int> ret = sol.searchRange(vec, 0);
    for(int i=0; i<ret.size(); i++){
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}
