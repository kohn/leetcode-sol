class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int this_run = 0;
        for(int i=1; i<prices.size(); i++){
            if(this_run + prices[i] - prices[i-1] < 0){
                this_run = 0;
            } else{
                this_run += prices[i]-prices[i-1];
                if(max < this_run)
                    max = this_run;
            }
        }
        return max;
    }
};
