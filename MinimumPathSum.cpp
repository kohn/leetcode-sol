#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>
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
    int get(vector<vector<int>>& grid, int i, int j){
        if(i<0)
            return INT_MAX;
        if(j<0)
            return INT_MAX;
        return grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dist(row, vector<int>(col, 0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
		if(i ==0 && j==0)
		    dist[i][j] = grid[i][j];
		else
		    dist[i][j] = min(get(dist, i-1, j), get(dist, i, j-1))+grid[i][j];
		cout << i << " " << j << " " << dist[i][j] << endl;
            }
        }
        return dist[row-1][col-1];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<vector<int>> v{
	{1,4,8,6,2,2,1,7},
	{4,7,3,1,4,5,5,1},
	{8,8,2,1,1,8,0,1},
	{8,9,2,9,8,0,8,9},
	{5,7,5,7,1,8,5,5},
	{7,0,9,4,5,6,5,6},
	{4,9,9,7,9,1,9,0}
    };

    vector<vector<int>> vv{
	{1,2},
	{1,1}
    };

    cout << sol.minPathSum(vv) << endl;
    return 0;
}
