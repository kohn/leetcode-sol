class Solution {
public:
    static int comp(pair<int, int> &a, pair<int, int> &b){
        return a.second - b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            auto it = m.find(nums[i]);
            if(it == m.end()){
                m[nums[i]] = 1;
            } else{
                it->second += 1;
            }
        }
        vector<pair<int, int> > vmap;
        // priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        priority_queue<pair<int, int> > q;
        for(auto it = m.begin(); it != m.end(); it++){
            int f = it->first;
            int s = it->second;
            // vmap.push_back(make_pair(f, s));
            q.push(make_pair(s, f));
        }
        
        //sort(vmap.begin(), vmap.end(), comp);
        
        vector<int> ret;
        for(int i=0; i<k; i++){
            //ret.push_back(vmap[i].second);
            ret.push_back(q.top().second);
            q.pop();
        }
        return ret;
    }
};
