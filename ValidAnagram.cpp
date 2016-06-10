class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        int count_t[26] ={0};
        for(char ch:s){
            count[ch-'a']++;
        }
        
        for(char ch:t){
            count_t[ch-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(count[i] != count_t[i])
                return false;
        }
        return true;
    }
};
