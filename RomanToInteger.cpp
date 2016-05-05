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
private:
    int digits[256];
public:
    Solution(){
        digits['I'] = 1;
        digits['V'] = 5;
        digits['X'] = 10;
        digits['L'] = 50;
        digits['C'] = 100;
        digits['D'] = 500;
        digits['M'] = 1000;
    }

    int romanToInt(string s) {
        int sum = 0;
        int last = 0;
        for(int i=0; i<s.size(); i++){
            if(i+1 < s.size() && digits[s[i+1]] > digits[s[i]]){
                sum += digits[s[i+1]] - digits[s[i]];
                i++;
            } else{
                sum += digits[s[i]];
            }
        }
        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::cout << sol.romanToInt("MCCXXX") << std::endl;

    return 0;
}
