class Solution {
public:

    int numSquares(int n) {
        vector<int> squares;
        vector<int> nums(n+1, INT_MAX);
        for(int i=1; i*i<=n; i++){
            squares.push_back(i*i);
            nums[i*i] = 1;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<squares.size() && squares[j]<i; j++){
                if(nums[i] > 1+nums[i-squares[j]])
                    nums[i] = 1 + nums[i-squares[j]];
            }
        }
        return nums[n];
    }
};
