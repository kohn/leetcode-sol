class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        set<int> s;
        if(x==z || y==z || z==0)
            return true;
        if(x>y)
            return canMeasureWater(y, x, z);
        if(x<=0)
            return false;
        queue<int> q;
        q.push(x);
        q.push(y);
        while(!q.empty()){
            int ele = q.front();
            if(ele == z || ele+x == z || ele+y == z)
                return true;
            q.pop();
            if(s.find(ele) == s.end()){
                s.insert(ele);
                int a = x>ele?(x-ele)%x:(ele-x)%x;
                int b = y>ele?(y-ele)%y:(ele-y)%y;
                q.push(a);
                q.push(b);
            }
        }
        return false;
    }
};
