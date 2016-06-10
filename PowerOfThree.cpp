class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        int max = 1162261467;
        return max%n == 0;
    }
};
