class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i=0; i<citations.size(); i++){
            int n = citations[i];
            int tmp_h = min(n, i+1);
            if(h<tmp_h)
                h = tmp_h;
        }
        return h;
    }
};
