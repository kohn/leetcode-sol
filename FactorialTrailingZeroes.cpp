#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        unsigned int power = 5;
        while(power <= (unsigned int)n){
            count += n/(int)power;
	    cout << power << " " << n/(int)power << " " << count << endl;
	    if(power * 5 / 5 != power)
		break;
            power *= 5;
        }
        return count;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    cout << sol.trailingZeroes(1808548329);
    return 0;
}
