#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==0)
            return true;
            
        int digit = 1;
        int tmp = x;
        int high = 1;
        while(tmp > 9){
            tmp/=10;
            digit++;
            high*=10;
        }
        if(digit == 1)
            return true;
        int low = 10;
        for(int i=0; i<=(digit+1)/2-1; i++){
            if(high<=1)
                return true;
            int high_bit = x/high;
            int low_bit = x%low;
            if(high_bit!=low_bit)
                return false;
            x -= high_bit*high;
            x = (x-low_bit)/low;
            high/=100;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    if(s.isPalindrome(1000000001))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
