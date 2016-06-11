#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0)
            return;
        int size = nums.size();
	k = k % size;
        for(int i=0; i<size; i++){
            int right_pos = i;
            do{
                right_pos = (right_pos-k+size)%size;
            } while(right_pos < i);
            int tmp = nums[i];
            nums[i] = nums[right_pos];
            nums[right_pos] = tmp;
        }
    }
};


int main(int argc, char *argv[]) {
    vector<int> v = {1, 2};
    Solution sol;
    sol.rotate(v, 3);
    for(auto &i : v){
	cout << i << " ";
    }
    cout << endl;
    return 0;
}
