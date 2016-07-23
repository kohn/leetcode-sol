class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for(int i=31; i>=0; i--){
            int mask = 1<<i;
            if((m&mask) == (n&mask)){
                res |= m&mask;
            } else{
                break;
            }
        }
        return res;
    }
};
