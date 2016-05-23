#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void init(bool *arr){
	for(int i=0; i<10; i++)
	    arr[i] = false;
    }
    bool isValidSudoku(vector<string>& board) {
        for(int i=0; i<9; i++){
            bool arr[10];
            bool arr_v[10];
	    init(arr);
	    init(arr_v);
            for(int j=0; j<9; j++){
                char grid = board[i][j];
                char grid_v = board[j][i];
                if(grid != '.'){
                    if(arr[grid-'0'] == true){
                        return false;
		    }
                    else
                        arr[grid-'0'] = true;
                }
                
                if(grid_v != '.'){
                    if(arr_v[grid_v-'0'] == true){
                        return false;
		    }
                    else
                        arr_v[grid_v-'0'] = true;
                }
            }
        }

        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                bool arr[10];
		init(arr);
                for(int m=i; m<i+3; m++){
                    for(int n=j; n<j+3; n++){
                        char grid = board[m][n];
                        if(grid != '.'){
                            if(arr[grid-'0'] == true)
                               return false;
                            else
                                arr[grid-'0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]){
    Solution sol;
    vector<string> board;
    board.push_back(".87654321");
    board.push_back("2........");
    board.push_back("3........");
    board.push_back("4........");
    board.push_back("5........");
    board.push_back("6........");
    board.push_back("7........");
    board.push_back("8........");
    board.push_back("9........");
    bool ret = sol.isValidSudoku(board);
    cout << ret << endl;
    return 0;
}
