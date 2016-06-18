#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
	unordered_map<int, bool> m;
	while(1){
	    int new_number = 0;
	    while(n!=0){
		new_number += (n%10)*(n%10);
		n /= 10;
	    }
	    if(new_number == 1)
		return true;

	    if(m.find(new_number) != m.end()){
		return false;
	    } else{
		m[new_number] = true;
	    }
	    n = new_number;
	}
    }
};

int main(int argc, char *argv[]) {

    Solution sol;
    cout << sol.isHappy(19) << endl;
    cout << sol.isHappy(68) << endl;
    return 0;
}
