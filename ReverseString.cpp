class Solution {
public:
    string reverseString(string s) {
        string str;
        for(string::reverse_iterator rit = s.rbegin();
            rit != s.rend();
            rit++){
                str.push_back(*rit);
            }
        return str;
    }
};
