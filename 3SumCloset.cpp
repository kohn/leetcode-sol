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
  inline int myabs(int a){
    return a<0?-a:a;
  }
    
  int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() <= 3){
      int sum = 0;
      for(int i:nums){
	sum += i;
      }
      return sum;
    }
				
    sort(nums.begin(), nums.end());
    int closest = numeric_limits<int>::max();
    for(int i=0; i<nums.size()-2; i++){
      if(i>0 && nums[i] == nums[i-1])
	continue;
      for(int j=i+1; j<nums.size()-1; j++){
	if(j>i+1 && nums[j] == nums[j-1])
	  continue;
	int size = nums.size()-j-1;
	int start = j;
	int k = start+(size+1)/2;
	while(size > 0){
	  int sum = nums[i] + nums[j] + nums[k];
	  if(sum == target)
	    return sum;

	  if(sum > target){
	    if(myabs(closest-target) > myabs(sum-target))
	      closest = sum;
	    size = k-start-1;
	    k = start+(size+1)/2;
	  } else{
	    start = k;
	    size = nums.size()-1-j;
	    k = start + (size+1)/2;
	  }
	}
      }
    }
    return closest;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;
  vector<int> vec{-1,2,1,-4};
  vector<int> a{-10,0,-2,3,-8,1,-10,8,-8,6,-7,0,-7,2,2,-5,-8,1,-4,6};
  cout << sol.threeSumClosest(a, 18) << endl;
  return 0;
}
