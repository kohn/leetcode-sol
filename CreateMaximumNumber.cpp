#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void pick(vector<int> &res, vector<int> &nums, int n){
	int i = 0;
	while(n--){
	    int max = i;
	    for(;i<=nums.size()-n-1; i++){
		if(nums[i] > nums[max])
		    max = i;
	    }
	    res.push_back(nums[max]);
	    i = max+1;
	}
    }

    void find_equal_max(vector<int> &max, vector<int> &pick1, vector<int> &pick2, int &i, int &j){
	int k = 1;
	for(; k<pick1.size()-i && k<pick2.size()-j; k++){
	    if(pick1[i+k] > pick2[j+k]){
		max[i+j] = pick1[i];
		i++;
		return;
	    } else if(pick1[i+k] < pick2[j+k]){
		max[i+j] = pick2[j];
		j++;
		return;
	    } else
		continue;
	}

	if(pick1.size()-i > pick2.size()-j){
	    for(int k=0; k<pick1.size()-i && k<pick2.size()-j; k++){
		max[i+j] = pick1[i];
		i++;
	    }
	} else{
	    for(int k=0; k<pick1.size()-i && k<pick2.size()-j; k++){
		max[i+j] = pick2[j];
		j++;
	    }
	}
    }
  

    void find_max(vector<int> &max , vector<int> &pick1, vector<int> &pick2){
	vector<int> tmp_max(max.size(), 0);
	int i=0, j=0;
	while(i<pick1.size() && j<pick2.size()){
	    if(pick1[i] > pick2[j]){
		tmp_max[i+j] = pick1[i];
		i++;
	    } else if(pick1[i] < pick2[j]){
		tmp_max[i+j] = pick2[j];
		j++;
	    } else{
		find_equal_max(tmp_max, pick1, pick2, i, j);
	    }
	}

	if(i<pick1.size()){
	    for(; i<pick1.size(); i++){
		tmp_max[i+j] = pick1[i];
	    }
	}

	if(j<pick2.size()){
	    for(; j<pick2.size(); j++){
		tmp_max[i+j] = pick2[j];
	    }
	}

	for(int i=0; i<max.size(); i++){
	    if(max[i] == tmp_max[i])
		continue;
	    else if(max[i] > tmp_max[i])
		return;
	    else{
		for(int j=i; j<max.size(); j++){
		    max[j] = tmp_max[j];
		}
		return;
	    }
	}
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<int> max(k, 0);
	for(int i=0; i<=k; i++){
	    vector<int> pick1;
	    vector<int> pick2;

	    if(k-i > nums1.size() || i>nums2.size())
		continue;
	    pick(pick1, nums1, k-i);
	    pick(pick2, nums2, i);
	    find_max(max, pick1, pick2);
	}
	return max;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> nums1 = {3,3,3,2,3,7,3,8,6,0,5,0,7,8,9,2,9,6,6,9,9,7,9,7,6,1,7,2,7,5,5,1};
    vector<int> nums2 = {5,6,4,9,6,9,2,2,7,5,4,3,0,0,1,7,1,8,1,5,2,5,7,0,4,3,8,7,3,8,5,3,8,3,4,0,2,3,8,2,7,1,2,3,8,7,6,7,1,1,3,9,0,5,2,8,2,8,7,5,0,8,0,7,2,8,5,6,5,9,5,1,5,2,6,2,4,9,9,7,6,5,7,9,2,8,8,3,5,9,5,1,8,8,4,6,6,3,8,4,6,6,1,3,4,1,6,7,0,8,0,3,3,1,8,2,2,4,5,7,3,7,7,4,3,7,3,0,7,3,0,9,7,6,0,3,0,3,1,5,1,4,5,2,7,6,2,4,2,9,5,5,9,8,4,2,3,6,1,9};
    vector<int> res = sol.maxNumber(nums1, nums2, 160);
    for(auto &i : res){
	cout << i << " ";
    }
    cout << endl;
    return 0;
}
