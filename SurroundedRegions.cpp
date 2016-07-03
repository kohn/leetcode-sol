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

    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> open(board.size(), vector<bool>(board[0].size(), false));
	queue<pair<int, int>> q;
        for(int i=1; i<row-1; i++){
	    if(board[i][0] == 'O')
		q.push(make_pair(i, 0));
	    if(board[i][col-1] == 'O')
		q.push(make_pair(i, col-1));
        }
        
        for(int i=0; i<col; i++){
	    if(board[0][i] == 'O')
		q.push(make_pair(0, i));
	    if(board[row-1][i] == 'O')
		q.push(make_pair(row-1, i));
        }

	int y[] = {-1, 0, 1, 0};
	int x[] = {0, 1, 0, -1};

	while(!q.empty()){
	    pair<int, int> p = q.front();
	    q.pop();
	    int r = p.first;
	    int c = p.second;
	    if(open[r][c] == true)
		continue;
	    open[r][c] = true;
	    for(int i=0; i<4; i++){
		int r_pos = r+y[i];
		int c_pos = c+x[i];
		if(r_pos<0 || r_pos>=row || c_pos<0 || c_pos>=col)
		    continue;
		if(board[r_pos][c_pos] == 'O')
		    q.push(make_pair(r_pos, c_pos));
	    }
	}
        
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++){
                if(!open[i][j])
                    board[i][j] = 'X';
            }
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}
