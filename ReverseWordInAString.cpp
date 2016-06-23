class Solution {
public:
    void reverse(string &str, int s, int e){
        while(s < e){
            char ch = str[s];
            str[s] = str[e];
            str[e] = ch;
            s++;
            e--;
        }
    }
    void reverseWords(string &s) {
        reverse(s, 0, s.size()-1);
        int start = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' '){
                if(start == -1)
                    start = i;
            } else{
                if(start != -1){
                    reverse(s, start, i-1);
                    start = -1;
                } else{
                    s.erase(i, 1);
                    i--;
                }
            }
        }
        if(start != -1)
            reverse(s, start, s.size()-1);
        if(s[s.size()-1] == ' ')
            s.erase(s.size()-1, 1);
    }
};
