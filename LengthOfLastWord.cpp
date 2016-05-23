class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size();
        int count = 0;
        for(int i=length-1; i>=0; i--){
            if(s[i] == ' '){
                if(count==0)
                   continue;
                else
                    break;
            } else{
                count++;
            }
        }
        return count;
    }
};
