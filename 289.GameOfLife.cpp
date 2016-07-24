class Solution {
public:
    int live_neighbors(vector<vector<int>> &board, int r, int c){
        int r_p[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int c_p[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int live_count = 0;
        for(int i=0; i<8; i++){
            int r_pos = r+r_p[i];
            int c_pos = c+c_p[i];
            if(r_pos >=0 && r_pos<board.size() && c_pos>=0 && c_pos < board[0].size()){
                if(board[r_pos][c_pos] == 1)
                    live_count++;
            }
        }
        return live_count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0)
            return;
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> status(row, vector<int>(col, 0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int live = live_neighbors(board, i, j);
                if(board[i][j] == 0){
                    if(live == 3)
                        status[i][j] = 1;
                } else{
                    if(live == 2 || live == 3)
                        status[i][j] = 1;
                    else
                        status[i][j] = 0;
                }
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                board[i][j] = status[i][j];
            }
        }
    }
};
