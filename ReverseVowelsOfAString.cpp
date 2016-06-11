class Solution {
public:
    bool isVowel(char ch){
        switch(ch){
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'o':
            case 'O':
            case 'i':
            case 'I':
            case 'U':
            case 'u':
                return true;    
            default:
                return false;
        }
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            while(i<s.size() && !isVowel(s[i]))
                i++;
            while(j>=0 && !isVowel(s[j]))
                j--;
            if(i >= j)
                break;
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};
