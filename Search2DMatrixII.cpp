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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0)
            return false;
        int col = matrix[0].size();

        int lo = 0;
        int hi = row-1;
        int end_row = 0;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            if(matrix[mid][0] < target){
                lo = mid+1;
                end_row = lo;
            }
            else if(matrix[mid][0] == target)
                return true;
            else{
                end_row = hi;
                hi = mid-1;
            }
        }

        for(int i=0; i<end_row; i++){
            if(matrix[i][col-1] < target)
                continue;
            lo = 0;
            hi = col-1;
            while(lo <= hi){
                int mid = lo+(hi-lo)/2;
                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] < target){
                    lo = mid+1;
                } else
                    hi = mid-1;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}
