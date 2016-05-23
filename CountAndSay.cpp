#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int consecutive(string &str, int index){
        char c = str[index];
        for(int i=index+1; i<str.size(); i++)
            if(str[i] != c)
                return i-index;
        return str.size()-index;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int i=0; i<n-1; i++){
            stringstream ss;
            int index = 0;
            while(index < s.size()){
                int con = consecutive(s, index);
                ss << con << s[index];
                index += con;
            }
            s = ss.str();
        }
        return s;
    }
};

int main(int argc, char *argv[]){
    Solution sol;
    cout << sol.countAndSay(4) << endl;
    return 0;
}
