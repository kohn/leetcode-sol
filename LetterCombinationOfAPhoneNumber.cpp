#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <assert.h>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:
    vector<string> num = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    Solution(){
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        for(int i=0; i<digits.size(); i++){
            string &chars = num[digits[i]-'0'];
            if(i==0){
                for(int k=0; k<chars.size(); k++){
                    string tmp;
                    tmp.push_back(chars[k]);
                    ret.push_back(tmp);
                }
                continue;
            }
            int size = ret.size();
            for(int j=0; j<size; j++){
                string now = ret[j];
                for(int k=0; k<chars.size(); k++){
                    if(k==0){
                        ret[j].push_back(chars[k]);
                    }
                    else{
                        string tmp = now;
                        tmp.push_back(chars[k]);
                        ret.push_back(tmp);
                    }
                }
            }
        }
        return ret;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> ret = sol.letterCombinations("");
    for(int i=0; i<ret.size(); i++){
        cout << ret[i] << " ";
    }
    
    return 0;
}
