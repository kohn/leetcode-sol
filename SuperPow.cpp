#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void print(vector<int> &v){
    for(auto i:v){
	cout << i << " ";
    }
    cout << endl;
}

void print(vector<vector<int>> &v){
    for(auto &i:v){
	print(i);
    }
}

class Solution {
public:
    // base < 1337, 0<=p<=10
    int pow(int base, int p){
        if(p == 0)
            return 1;
        if(p%2 == 1)
            return (pow(base, p-1)*base)%1337;
        else{
            int tmp = pow(base, p/2);
            return (tmp*tmp)%1337;
        }
    }
    
    int superPow(int a, vector<int>& b) {
	int size = b.size();
        if(size == 0)
            return 0;
        int pow_a_10 = a%1337;
        int res = 1;
	for(int i=size-1; i>=0; i--){
            cout << res << " " << pow_a_10 << endl;
            res = (res*pow(pow_a_10, b[i]))%1337;
            pow_a_10 = pow(pow_a_10, 10);
	}
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> v = {1, 1};
    cout << sol.superPow(2, v) << endl;
    return 0;
}
