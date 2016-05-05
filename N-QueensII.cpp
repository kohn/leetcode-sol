#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int count;
    void put_into_res(int **m, int n){
        count++;
    }
    int ok_after_set(int **m, int n, int i, int j){
        for(int k=0; k<i; k++){
            if(m[k][j] == 1)
                return 0;
        }
        for(int k=(i>j?j:i); k>0; k--){
            if(m[i-k][j-k] == 1)
                return 0;
        }
        for(int k=0; k<n ;k++){
            if(i-k>=0 && j+k <n){
                if(m[i-k][j+k] == 1)
                    return 0;
            }
        }
        return 1;
    }
    void iterate(int **m, int n, int i){
        if(i == n){
            put_into_res(m, n);
        }
        for(int j=0; j<n; j++){
            if(ok_after_set(m, n, i, j)){
                m[i][j] = 1;
                iterate(m, n, i+1);
                m[i][j] = 0;
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        count = 0;
        int **m = new int*[n];
        for (int i = 0; i < n; ++i){
            m[i] = new int[n];
            for(int j=0; j<n; j++){
                m[i][j] = 0;
            }
        }
        iterate(m, n, 0);
        return count;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.totalNQueens(8)<<endl;
    return 0;
}
