class Solution {
public:
    vector<vector<int>> rectangels;
    vector<int> range;
    Solution(vector<vector<int>>& rects) {        
        rectangels = rects;
        for(int i=0; i<rects.size(); i++) {
            int size = (rects[i][2] - rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
            if(range.size() == 0) {
                range.push_back(size);
            } else {
                range.push_back(size+range[range.size()-1]);
            }
        }
    }
    
    int randint(int start, int end) {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<std::mt19937::result_type> dist6(start, end);
        return dist6(rng);
    }
    
    vector<int> pick() {
        int rv = randint(1, range[range.size()-1]);
        auto upper = upper_bound(range.begin(), range.end(), rv);
        int index = upper - range.begin();
        if (index > 0 && range[index-1] == rv) {
            index = index - 1;
        }
        if (upper == range.end()) {
            index = range.size()-1;
        }
        vector<int> rect = rectangels[index];
        int rand_x = randint(rect[0], rect[2]);
        int rand_y = randint(rect[1], rect[3]);
        return vector<int>{rand_x, rand_y};
    }
};

/**
 * 最优解: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/discuss/446893/C%2B%2B-solution-using-std%3A%3Adiscrete_distribution
 * discrete_distribution 用于按照权重随机选择一个index
 * uniform_int_distribution 用于在start, end间选择一个随机数
 * 值得注意的是: int size = (rects[i][2] - rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
 * 这里计算每个长方形面积(也就是权重)的时候, 需要+1. 因为边上的点也算进去. 比如(1,1), (2,2)这样一个边长为1的长方形
 * x可选的点是1和2, y方向也可以选1和2. 最终有2*2=4中情况.
 */
class Solution {
  vector<vector<int>> rects;
  mt19937 rng;
  discrete_distribution<int> dist;
    
public:
  Solution(vector<vector<int>>& rects_): 
    rects(rects_),
    rng(random_device()())
  {
    vector<int> weights(rects.size());
    for (int i = 0; i < rects.size(); ++i) {
      weights[i] = (rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
    }
    dist = discrete_distribution<int>(weights.begin(), weights.end());
  }
    
  vector<int> pick() {
    auto &r = rects[dist(rng)];
    int x = uniform_int_distribution<int>(r[0], r[2])(rng);
    int y = uniform_int_distribution<int>(r[1], r[3])(rng);
    return {x, y};
  }
};
