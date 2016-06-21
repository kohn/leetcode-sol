#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
	vector<bitset<26> > bitsets;
	for(auto &s : words){
	    bitset<26> b;
	    for(auto c : s){
		b.set(c-'a');
	    }
	    bitsets.push_back(b);
	}

	int max = 0;
	for(int i=0; i<bitsets.size(); i++){
	    for(int j=i+1; j<bitsets.size(); j++){
		bitset<26> t = bitsets[i]&bitsets[j];
		if(t.count() == 0){
		    int product = words[i].length() * words[j].length();
		    if(product > max)
			max = product;
		}
	    }
	}
	return max;
    }
};


int main(int argc, char *argv[]) {
    Solution sol;
    vector<string> vec = {"abc", "def", "aaa", "aaaa"};
    cout << sol.maxProduct(vec) << endl;
    return 0;
}
