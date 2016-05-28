#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
	int l = 0;
	int r = height.size()-1;
	int last = 0;
	int water = 0;
	while(l <= r){
	    if(height[l] <= height[r]){
		if(height[l] < last)
		    water += last - height[l];
		else
		    last = height[l];
		l++;
	    } else{
		if(height[r] < last)
		    water += last - height[r];
		else
		    last = height[r];
		r--;
	    }
	}
	return water;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
    return 0;
}
