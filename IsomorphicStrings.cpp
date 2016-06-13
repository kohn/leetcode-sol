class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map[256] = {0};
        char mapped[256] = {0};
        for(int i=0; i<s.size(); i++){
            if(map[s[i]] == 0){
                if(mapped[t[i]] !=0 && mapped[t[i]] != s[i])
                    return false;
                map[s[i]] = t[i];
                mapped[t[i]] = s[i];
            } else{
                if(map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
