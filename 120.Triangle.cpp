class Solution {
public:
    inline int Min(int a, int b){
        return a<b?a:b;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if(rows == 0)
            return 0;
        vector<vector<int>> dp(rows, vector<int>(rows, 0));
        dp[0][0] = triangle[0][0];
        int sum = dp[0][0];
        for(int i=1; i<rows; i++){
            int min = INT_MAX;
            for(int j=0; j<triangle[i].size(); j++){
                if(j == 0)
                    dp[i][j] = dp[i-1][j]+triangle[i][j];
                else if(j == triangle[i-1].size())
                    dp[i][j] = dp[i-1][j-1]+triangle[i][j];
                else
                    dp[i][j] = Min(dp[i-1][j-1], dp[i-1][j])+triangle[i][j];
                if(dp[i][j] < min)
                    min = dp[i][j];
            }
            sum = min;
        }
        return sum;
    }
};
