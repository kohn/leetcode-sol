class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for(char c : s){
            sum = sum*26+c-'A'+1;
        }
        return sum;
    }
};
