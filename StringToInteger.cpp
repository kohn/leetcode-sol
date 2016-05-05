#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    const unsigned int MAX = 2147483647;
    const unsigned int MIN = 2147483648;
    const int MM = 0x7fffffff/10;
    int myAtoi(string str) {
        int sign = 1;
        int start = 0;
        int i=0;
        int num = 0;
        while(str[start]==' ')
            start++;
        
        if(str[start]=='+' || str[start]=='-'){
            if(str[start] == '-')
                sign = -1;
            start++;
        }
        
        for(int i=start; i<str.length(); i++){
            if(str[i] >'9' || str[i] < '0')
                break;
            
            if(num>MM)
                return sign==1?2147483647:-2147483648;
            unsigned int tmp = num*10 + str[i]-'0';
            if((sign==1 && tmp > MAX) || (sign==-1 && tmp>MIN))
                return sign==1?2147483647:-2147483648;
            else
                num = (int)tmp;
        }
        return num*sign;
    }
};
