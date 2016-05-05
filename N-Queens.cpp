#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string> > res;
    void put_into_res(int **m, int n){
        vector<string> vec;
        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<n; j++){
                s.push_back(m[i][j]==1?'Q':'.');
            }
            vec.push_back(s);
        }
        res.push_back(vec);
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
    vector<vector<string> > solveNQueens(int n) {
        int **m = new int*[n];
        for (int i = 0; i < n; ++i){
            m[i] = new int[n];
            for(int j=0; j<n; j++){
                m[i][j] = 0;
            }
        }
        iterate(m, n, 0);
        return res;
    }
};

void print(vector<vector<string> > v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] <<endl;
        }
        cout<<endl;
    }
}
int main(int argc, char *argv[])
{
    Solution s;
    print(s.solveNQueens(9));
    return 0;
}
