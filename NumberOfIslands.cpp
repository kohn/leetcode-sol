#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int root(vector<int> &disjoint, int index){
        int r = index;
        while(r!=disjoint[r])
            r = disjoint[r];
        disjoint[index] = r;
        return r;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int columns = grid[0].size();
        vector<int> disjoint(rows*columns);
        for(int i=0; i<disjoint.size(); i++)
            disjoint[i] = i;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(i+1<rows && grid[i][j] == '1' && grid[i+1][j] == '1')
                    disjoint[root(disjoint, (i+1)*columns+j)] = root(disjoint, i*columns+j);
                if(j+1<columns && grid[i][j] == '1' && grid[i][j+1] == '1')
                    disjoint[root(disjoint, i*columns+j+1)] = root(disjoint, i*columns+j);
            }
        }
        int count = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == '1' && disjoint[i*columns+j] == i*columns+j)
                    count++;
            }
        }
        return count;
                
    }
};

int main(int argc, char *argv[]) {
    vector<vector<char>> grid = {
	{'1','1','1','1','0'},
	{'1','1','0','1','0'},
	{'1','1','0','0','0'},
	{'0','0','0','0','0'}
    };
    Solution sol;
    cout << sol.numIslands(grid) << endl;
    return 0;
}
