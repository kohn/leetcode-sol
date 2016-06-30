class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 0;
        int hi = num;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            long long res = (long long)mid*(long long)mid;
            if(res > (long long)num)
                hi = mid-1;
            else if(res < (long long)num)
                lo = mid+1;
            else
                return true;
        }
        return false;
    }
};
