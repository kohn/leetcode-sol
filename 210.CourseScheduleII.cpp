// preCount为0的数字压入一个队列, 然后不断pop队列, 并对pop出来这门课的后置课程全部减一, 减完后
// 如果前置课程为0了, 继续压入队列. 这样就是拓扑排序了
// 下面这种实现方式, 每次都遍历所有preCount, 复杂度为n^2, 不如拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependency;
        vector<int> preCount;
        for(int i=0;i<numCourses; i++) {
            vector<int> vec;
            dependency.push_back(vec);
            preCount.push_back(0);
        }

        for(int i=0; i<prerequisites.size(); i++) {
            dependency[prerequisites[i][1]].push_back(prerequisites[i][0]);
            preCount[prerequisites[i][0]]+=1;
        }

        vector<int> result;
        while(result.size()<numCourses) {
            int i=0;
            for(;i<preCount.size();i++) {
                if(preCount[i] == 0) {
                    break;
                }
            }

            if(i==preCount.size()) {
                vector<int> emptyResult;
                return emptyResult;
            }

            preCount[i]-=1;
            result.push_back(i);
            for(int j=0; j<dependency[i].size();j++) {
                preCount[dependency[i][j]]-=1;
            }
        }
        return result;
    }
};
