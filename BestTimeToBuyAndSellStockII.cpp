class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool bought_flag = false;
        int start_price = 0;
        int profit = 0;
        for(int i=0; i<prices.size(); i++){
            if(bought_flag && i+1 < prices.size() && prices[i]>prices[i+1]){
                bought_flag = false;
                profit += prices[i] - start_price;
            } else if(bought_flag == false && i+1 < prices.size() && prices[i]<prices[i+1]){
                bought_flag = true;
                start_price = prices[i];
            }
        }
        if(bought_flag){
            profit+=prices[prices.size()-1]-start_price;
        }
        return profit;
    }
};
