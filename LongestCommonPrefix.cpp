#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <assert.h>
#include <list>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int longest=0;
        if(strs.size() == 0)
            return "";
        while(1){
            if(longest == strs[0].size())
                return strs[0];
                
            char test_char = strs[0][longest];
            for(int i=1; i<strs.size(); i++){
                if(strs[i][longest] != test_char){
                    return strs[0].substr(0, longest);
                }
            }
            longest++;
        }
    }    
};

int main(int argc, char *argv[])
{
    Solution sol;
    return 0;
}
