class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n!=0){
            char ch = 'A' + (n-1)%26;
            n = (n-1)/26;
            ret.insert(0, 1, ch);
        }
        return ret;
    }
};
