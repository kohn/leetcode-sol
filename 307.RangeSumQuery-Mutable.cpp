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

class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    int read(int idx){
        idx += 1;
        int sum = 0;
        while(idx > 0){
            sum += tree[idx];
            idx -= (idx&-idx);
        }
        return sum;
    }
    void update_tree(int idx, int val){
        idx = idx+1;
        while(idx<tree.size()){
            tree[idx] += val;
            idx += (idx&-idx);
        }
    }
    NumArray(vector<int> &n) : tree(n.size()+1, 0),
                                nums(n){
        for(int i=0; i<nums.size(); i++){
            update_tree(i, nums[i]);
        }
    }
    void update(int i, int val) {
        int diff = val-nums[i];
        nums[i] = val;
        update_tree(i, diff);
    }
    int sumRange(int i, int j) {
        if(i == 0)
            return read(j);
        int sum_left = read(i-1);
        int sum_right = read(j);
        return sum_right-sum_left;
    }
};


// Your NumArray object will be instantiated and called as such:


int main(int argc, char *argv[]) {
    vector<int> nums{1,3,5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;
    return 0;
}
