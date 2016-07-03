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


class Solution {
public:
    // int hIndex(vector<int>& citations) {
    //     int h = 0;
    //     int size = citations.size();
    //     for(int i=size-1; i>=0; i--){
    //         int n = citations[i];
    //         int tmp_h = min(n, size-i);
    //         if(h<tmp_h)
    //             h = tmp_h;
    //     }
    //     return h;
    // }
    int hIndex(vector<int>& citations) {
	int lo = 0;
	int hi = citations.size()-1;
	int max_h = 0;
	int size = citations.size();
	while(lo <= hi){
	    int mid = lo + (hi-lo)/2;
	    int n = citations[mid];
	    int h;
	    if(n > size-mid){
		h = size-mid;
		hi = mid-1;
	    } else{
		h = n;
		lo = mid+1;
	    }

	    if(h > max_h)
		max_h = h;
	}
	return max_h;
    }
    
};


int main(int argc, char *argv[]) {
    Solution sol;
    vector<int> citations{0,1,3,5,6};
    cout << sol.hIndex(citations) << endl;
    return 0;
}
