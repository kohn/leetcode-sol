#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<vector<char>>& board, int i, int j, string &word, int m, vector<vector<bool>> &visited){
        int x[] = {0, 1, 0, -1};
        int y[] = {-1, 0, 1, 0};
	// cout << i << ", " << j << ": " << word[m] << endl;;	
        if(m == word.size()-1)
            return true;
        for(int k=0; k<4; k++){
            int x_pos = i+x[k];
            int y_pos = j+y[k];
            if(x_pos < board[0].size() && x_pos >=0 && y_pos>=0 && y_pos<board.size()){
                if(board[y_pos][x_pos] == word[m+1] && !visited[y_pos][x_pos]){
                    visited[y_pos][x_pos] = true;
                    if(search(board, x_pos, y_pos, word, m+1, visited))
                        return true;
                    visited[y_pos][x_pos] = false;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int index = 0;
        vector<vector<bool>> visited;
        if(word.size() == 0)
            return true;
        for(int i=0; i<board.size(); i++){
            vector<bool> tmp(board[i].size(), false);
            visited.push_back(tmp);
        }
        
        for(int i=0; i<board.size(); i++){
            vector<char> &v = board[i];
            for(int j=0; j<v.size(); j++){
                if(v[j] == word[index]){
                    visited[i][j] = true;
                    if(search(board, j, i, word, 0, visited))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<vector<char>> v;
    vector<char> v1 = {'a', 'a', 'a', 'a'};
    vector<char> v2 = {'a', 'a', 'a', 'a'};
    vector<char> v3 = {'a', 'a', 'a', 'a'};
    vector<char> v4 = {'a', 'a', 'a', 'a'};
    vector<char> v5 = {'a', 'a', 'a', 'b'};
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    cout << sol.exist(v, "aaaaaaaaaaaaaaaaaaaa") << endl;
    return 0;
}
