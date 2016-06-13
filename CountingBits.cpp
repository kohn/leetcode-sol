class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1);
        ret[0] = 0;
        ret[1] = 1;
        for(int i=2; i<=num; i*=2){
            for(int j=i; j<i*2 && j<=num; j++){
                if(j<i+i/2)
                    ret[j] = ret[j-i/2];
                else
                    ret[j] = ret[j-i]+1;
            }
        }
        return ret;
    }
};

