#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void print(vector<int> &&v){
    for(auto i:v){
	cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> graycodes{0};
        if(n == 0)
            return graycodes;
        graycodes.push_back(1);
        int p = 1;
        for(int i=1; i<n; i++){
            p*=2;
            for(int j=p; j<p*2; j++)
                graycodes.push_back(graycodes[p*2-j-1]+p);
        }
        return graycodes;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    print(sol.grayCode(2));
    return 0;
}
