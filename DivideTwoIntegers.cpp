#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <assert.h>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if(divisor == 0 || dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign = 1;
        if(dividend <0 && divisor > 0){
            sign = -1;
        } else if (dividend>0 && divisor<0){
            sign = -1;
        }

        long long dd = labs(dividend);
        long long dv = labs(divisor);
        int ans = 0;

        cout << dd << " " << dv <<endl;
        while(dd >= dv){
            long long d = dv;
            int ans_tmp = 1;
            while(dd >= d){
                ans_tmp = ans_tmp << 1;
                d = d << 1;
            }
            d = d >> 1;
            ans_tmp = ans_tmp >> 1;
            ans += ans_tmp;
            dd -= d;
        }
        return ans * sign;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << sol.divide(1000, 2) << endl;
    cout << sol.divide(-1010369383, INT_MIN) << endl;
    return 0;
}
