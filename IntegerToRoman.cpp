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
    string toRoman(int num, int level){
        static char digits[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string str;
        if(num <= 3){
            for(int i=0; i<num; i++){
                str.push_back(digits[level*2]);
            }
        } else if(num >=5 && num <9){
            str.push_back(digits[level*2+1]);
            for(int i=0; i<num-5; i++)
                str.push_back(digits[level*2]);
        } else if(num == 4){
            str.push_back(digits[level*2]);
            str.push_back(digits[level*2+1]);
        } else if(num == 9){
            str.push_back(digits[level*2]);
            str.push_back(digits[level*2+2]);
        }
        return str;
    }
    string intToRoman(int num){
        int level = 0;
        string ret;
        while(num != 0){
            int remain = num %10;
            ret = toRoman(remain, level) + ret;
            num /= 10;
            level++;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::cout << sol.intToRoman(1230) << std::endl;
    return 0;
}
