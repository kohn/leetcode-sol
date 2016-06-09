#include <iostream>
#include <set>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
    set<int> nums;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        nums.insert(val);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        set<int>::iterator iter = nums.begin();
        while(iter != nums.end()){
            int start = *iter;
            int end = start;
            set<int>::iterator next_iter = ++iter;
            while(next_iter != nums.end()){
                if(*next_iter == end+1){
                    end++;
                    next_iter++;
                } else{
                    break;
                }
            }
            res.push_back(Interval(start, end));
            iter = next_iter;
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

int main(int argc, char *argv[])
{
    
    return 0;
}
