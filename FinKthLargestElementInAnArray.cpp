#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        int ret = 0;
        for(auto i : nums){
            q.push(i);
	}
	
        for(int i=0; i<k; i++){
            ret = q.top();
            q.pop();
        }
        return ret;   
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {2, 1};
    Solution sol;
    cout << sol.findKthLargest(nums, 1) << endl;
    return 0;
}

