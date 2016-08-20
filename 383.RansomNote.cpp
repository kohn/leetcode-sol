class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> chars_in_ransom(128, 0);
        vector<int> chars_in_magazine(128, 0);
        for(int i=0; i<ransomNote.size(); i++){
            chars_in_ransom[ransomNote[i]]++;
        }
        for(int i=0; i<magazine.size(); i++){
            chars_in_magazine[magazine[i]]++;
        }
        for(int i=0; i<128; i++){
            if(chars_in_ransom[i] > chars_in_magazine[i])
                return false;
        }
        return true;
    }
};
