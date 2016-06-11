class Solution {
public:
    bool isAlphaNumeric(char &ch){
        if(ch >= 'A' && ch <='Z')
            ch = ch-'A'+'a';
        if(ch <= 'z' && ch >='a')
            return true;
        if(ch <= '9' && ch >= '0')
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        int i=0;
        int j=s.size()-1;
        while(1){
            while(i<s.size() && !isAlphaNumeric(s[i]))
                i++;
            while(j>=0 && !isAlphaNumeric(s[j]))
                j--;
            if(i >= j)
                return true;
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
    }
};
