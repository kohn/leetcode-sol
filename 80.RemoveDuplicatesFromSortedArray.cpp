class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         if(nums.size() <= 2)
            return nums.size();
        int count = 1;
        for(vector<int>::iterator iter = nums.begin()+1;
            iter != nums.end(); ){
                if(*iter == *(iter-1)){
                    if(count == 2){
                        iter = nums.erase(iter);
                        continue;
                    }
                    else
                        count++;
                } else{
                    count = 1;
                }
                iter++;
            }
        return nums.size();
    }
};
