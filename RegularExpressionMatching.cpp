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
    bool A[1000][1000];
    bool match(char char_s, char char_p){
        if(char_p == '.')
            return true;
        else if(char_s == char_p)
            return true;
        return false;
    }

    inline void set(int i, int j, bool val){
        A[i+1][j+1] = val;
        cout << i+1 << " " << j+1 << " " << val << endl;
    }

    inline bool get(int i, int j){
        return A[i+1][j+1];
    }
    
    bool isMatch(string s, string p) {
        memset(A, 0, sizeof(A));
        A[0][0] = true;

        for(int i=0; i<p.size(); i++){
            if(p[i] == '*'){
                set(-1, i, get(-1, i-1));
                continue;
            }
            if(i+1 < p.size() && p[i+1] == '*'){
                set(-1, i, true);
            } else{
                break;
            }
        }
        
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<p.size(); j++){
                if(p[j] == '*'){
                    set(i, j, get(i, j-1));
                    continue;
                }
                
                char ch_p = p[j];
                if(j+1 < p.size() && p[j+1] == '*'){
                    if(match(s[i], ch_p)){
                        if(get(i-1, j-1) || get(i-1, j) || get(i, j-1))
                            set(i, j, true);
                    } else{
                        if(get(i, j-1))
                            set(i, j, true);
                    }
                } else{
                    if(match(s[i], ch_p)){
                        set(i, j, get(i-1, j-1));
                    }
                    else {
                        set(i, j, false);
                    }
                }
            }
        }
        return get(s.size()-1, p.size()-1);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::cout << sol.isMatch("aa", "a") << std::endl;
    std::cout << sol.isMatch("aa", "aa") << std::endl;
    std::cout << sol.isMatch("aaa", "aa") << std::endl;
    std::cout << sol.isMatch("aa", "a*") << std::endl;
    std::cout << sol.isMatch("aa", ".*") << std::endl;
    std::cout << sol.isMatch("ab", ".*") << std::endl;
    std::cout << sol.isMatch("aab", "c*a*b") << std::endl;
    std::cout << sol.isMatch("aaa", "ab*a*c*a") << std::endl;
    std::cout << sol.isMatch("ab", ".*c") << std::endl;
    std::cout << sol.isMatch("ab", ".*..") << std::endl;
    std::cout << sol.isMatch("afafas", ".*af.*af.*s") << std::endl;
    std::cout << sol.isMatch("afaf", ".*af.*af") << std::endl;
    return 0;
}
