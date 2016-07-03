class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        int size = citations.size();
        for(int i=size-1; i>=0; i--){
            int n = citations[i];
            int tmp_h = min(n, size-i);
            if(h<tmp_h)
                h = tmp_h;
        }
        return h;
    }
};
