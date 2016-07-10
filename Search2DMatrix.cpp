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


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0)
            return false;
        int col = matrix[0].size();
        int lo = 0;
        int hi = row-1;
        while(lo < hi){
            int mid = lo+(hi-lo)/2;
            if(matrix[mid][0] < target)
                lo = mid+1;
            else if(matrix[mid][0] > target)
                hi = mid-1;
            else
                return true;
        }
        int r = lo;
	if(matrix[r][0] > target)
	    r--;
	if(r<0)
	    return false;
	cout << r << endl;
        lo = 0;
        hi = col-1;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            if(matrix[r][mid] < target)
                lo = mid+1;
            else if(matrix[r][mid] > target)
                hi = mid-1;
            else
                return true;
        }
        return false;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    
    vector<vector<int>> v{
	{1,3,5,7},
	{10,11,16,20},
	{23,30,34,50}
    };

    vector<vector<int>> vv{
	{1}
    };

    cout << sol.searchMatrix(v, 11) << endl;
    return 0;
}
