#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, vector<pair<int, int> > &waves, int lo, int hi){
	if(lo > hi)
	    return 0;
	int min = prices[waves[lo].first];
	int max_profit = 0;
	for(int i=lo; i<=hi; i++){
	    if(prices[waves[i].first] < min)
		min = prices[waves[i].first];
	    if(prices[waves[i].second] - min > max_profit)
		max_profit = prices[waves[i].second] - min;
	}
	return max_profit;
    }
    
    int maxProfit(vector<int>& prices) {
	vector<pair<int, int> > waves;
	for(int i=0; i<prices.size(); i++){
	    int j = i+1;
	    for(; j<prices.size(); j++){
		if(prices[j] < prices[j-1])
		    break;
	    }
	    j = j-1;
	    if(j>i)
		waves.push_back(make_pair(i, j));
	    i = j;
	}

	for(auto &i : waves){
	    cout << i.first << " " << i.second << endl;
	}

	int max_profit = 0;
	for(int i=0; i<waves.size(); i++){
	    int left_profit = maxProfit(prices, waves, 0, i);
	    int right_profit = maxProfit(prices, waves, i+1, waves.size()-1);
	    cout << left_profit << " " << right_profit << endl;
	    if(left_profit+right_profit > max_profit)
		max_profit = left_profit+right_profit;
	}
	return max_profit;
    }
};


int main(int argc, char *argv[]) {
    vector<int> prices = {9,9,0,3,0,7,7,7,4,1,5,0,1,7};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
