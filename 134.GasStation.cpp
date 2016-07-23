class Solution {
public:

    int start(vector<int>& diff){
        int size = diff.size();
        for(int i=0; i<size; i++){
            int sum = 0;
            int j = 0;
            for(;j<size; j++){
                sum += diff[(i+j)%size];
                if(sum < 0){
                    i = i+j;
                    break;
                }
            }
            if(j == size)
                return i;
        }
        return -1;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        for(int i=0; i<gas.size(); i++){
            diff[i] = gas[i]-cost[i];
        }
        return start(diff);
    }
};
