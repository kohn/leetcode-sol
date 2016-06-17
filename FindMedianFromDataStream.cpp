#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MedianFinder {
public:

    vector<int> ds;
    int size;

    // Adds a number into the data structure.
    void addNum(int num) {
	size++;
        if(size == 1){
	    ds.push_back(num);
	} else{
	    if(num >= ds[ds.size()-1]){
		ds.push_back(num);
		return;
	    }
	    
	    vector<int>::iterator iter = ds.begin();
	    int lo = 0;
	    int hi = ds.size()-1;
	    while(lo < hi){
		int mid = lo + (hi-lo)/2;
		iter =ds.begin() + mid;
		if(*iter < num && *(iter+1) >= num){
		    ds.insert(iter+1, num);
		    return;
		}
		else if(*iter >= num)
		    hi = mid;
		else
		    lo = mid;
	    }
	    if(lo == hi){
		iter = ds.begin()+hi;
		ds.insert(iter, num);
	    }
	}
    }

    // Returns the median of current data stream
    double findMedian() {
	if(size%2==1){
	    return ds[ds.size()/2];
	} else{
	    return (ds[ds.size()/2-1] + ds[ds.size()/2])/2.0;
	}
    }

    void print(){
	for(int i:ds){
	    cout << i << " ";
	}
	cout << endl;
    }

    MedianFinder(){
	size = 0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(int argc, char *argv[]) {
    MedianFinder mf;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(10);
    mf.print();
    cout << mf.findMedian() << endl;
    mf.addNum(2);
    mf.print();
    cout << mf.findMedian() << endl;
    mf.addNum(6);
    mf.print();
    cout << mf.findMedian() << endl;
    return 0;
}
