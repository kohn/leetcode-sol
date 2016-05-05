#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
       stack<char> sta;
       for(auto c : s){
           if(c == '(' || c== '{' || c=='[')
                sta.push(c);
            else{
                if(sta.empty())
                    return false;
                char p = sta.top();
                sta.pop();
                if(c == ')' && p !='(')
                    return false;
                if(c == ']' && p != '[')
                    return false;
                if(c == '}' && p != '{')
                    return false;
            }
       }
       return sta.empty();
    }
};

int main(int argv, char *argv[]){
    
    return 0;
}
