class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int size = digits.size();
        for(int i=size-1; i>=0; i--){
            digits[i] += 1;
            if(digits[i] == 10){
                digits[i] = 0;
                if(i == 0)
                    ret.push_back(1);
            }
            else
                break;
        }
        for(int i=0; i<size; i++)
            ret.push_back(digits[i]);
        return ret;
    }
};
