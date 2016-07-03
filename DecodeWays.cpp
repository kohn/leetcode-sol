class Solution {
public:
    
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 1);
        if(s.size() == 0)
            return 0;
        if(s[0] == '0')
            return 0;
        for(int i=1; i<s.size(); i++){
            if(s[i] == '0'){
                if(s[i-1] == '0' || s[i-1] > '2')
                    return 0;
                dp[i+1] = dp[i-1];
            }
            else if(s[i-1] >= '3' || s[i-1]=='2' && s[i]>='7' || s[i-1]=='0')
                dp[i+1] = dp[i];
            else
                dp[i+1] = dp[i]+dp[i-1];
        }
        return dp[s.size()];
    }
};
