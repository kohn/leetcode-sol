class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(128, 0);
        for(char c : s)
            vec[c]++;
        for(int i=0; i<s.size(); i++)
            if(vec[s[i]] == 1)
                return i;
        return -1;
    }
};
