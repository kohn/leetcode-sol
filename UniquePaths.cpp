class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
            return 0;
        vector<vector<int>> matrix(m, vector<int>(n, 1));
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        return matrix[m-1][n-1];
    }
};
