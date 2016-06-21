#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     int A(int n, int m){
//         if(m > n)
//             return 0;
//         unsigned long long tmp = 1ULL;
//         for(int i=0; i<m; i++)
//             tmp *= (n-i);
//         return (int)tmp;
//     }   
    
//     int C(int n, int m){
//         if(m>n/2)
//             return C(n, n-m);
//         unsigned long long tmp = 1ULL;
//         for(int i=0; i<m; i++)
//             tmp *= (n-i);
//         return (int)(tmp/(unsigned long long)A(m, m));
//     }

//     int countNumbersWithUniqueDigits(int n) {
//         int count = 0;
//         if(n == 1)
//             return 10;
//      int count_last_run = 0;
//         for(int i=2;  i<=n; i++){
//          int count_this_run = 0;
//          //for(int j=1; j<=i-1; j++)
//          count_this_run += (i-1)*A(9, i-2)+count_last_run;
//          for(int j=1; j<=i-2; j++){
//              count_this_run += C(i-2, j)*A(9, i-2-j);
//          }
//          count_this_run *= 9;
//          // cout << count_this_run << endl;
//          count += count_this_run;
//          // cout << count << endl;
//          count_last_run = count;
//         }
        
//         long long ret = 1LL;
//         for(int i=0; i<n; i++)
//             ret *= 10;
//         return ret-count;
//     }
// };


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int v = 9;
        int count = 10;
        if(n == 0)
            return 1;
        for(int i=9; i>=(9-n+2) ;i--){
            v *= i;
            count += v;
        }
        return count;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    for(int i=1; i<=5; i++)
        cout << "res of " << i << " = " << sol.countNumbersWithUniqueDigits(i) << endl << endl;
    
    return 0;
}
