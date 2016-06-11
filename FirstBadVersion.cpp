// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n <= 1)
            return n;
        int l = 1;
        int h = n;
        while(h-l > 1){
            int mid = l + (h-l)/2;
            if(isBadVersion(mid)){
                h = mid;
            } else{
                l = mid;
            }
        }
        if(isBadVersion(l))
            return l;
        else
            return h;
    }
};
