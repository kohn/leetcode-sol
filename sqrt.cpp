class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        int lo = 0;
        int hi = x;
        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if(mid*mid == (long long)x || mid*mid < (long long)x && (mid+1)*(mid+1)>(long long)x)
                return mid;
            if(mid*mid < (long long)x)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return hi;
    }
};
