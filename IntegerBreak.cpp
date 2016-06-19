#include <iostream>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
	if(n == 2)
	    return 1;
	if(n == 3)
	    return 2;
	int max_3 = 0;
	int remain = 0;
	switch(n%3){
	case 0:
	case 1:{
	    max_3 = n/3-1;
	    remain = n%3+3;
	    break;
	}
	case 2:{
	    max_3 = n/3;
	    remain = 2;
	}
	}

	int res = 1;
	for (int i = 0; i < max_3; i++) {
	    res *= 3;
	}
	res*= remain;
	return res;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    cout << sol.integerBreak(6) << endl;
    return 0;
}
