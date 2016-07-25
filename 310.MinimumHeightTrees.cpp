#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void print(vector<int> &v){
    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;
}

void print(vector<vector<int>> &v){
    for(auto &i:v){
	print(i);
    }
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> in(n, 0);
        vector<vector<int>> edge_matrix(n);
        int max = 0;
        for(auto &p : edges){
            edge_matrix[p.first].push_back(p.second);
            edge_matrix[p.second].push_back(p.first);
        }
        // print(edge_matrix);
        vector<int> nodes;
        for(int i=0; i<n; i++)
            nodes.push_back(i);
            
        vector<int> edge_count;
        for(int i=0; i<n; i++)
            edge_count.push_back(edge_matrix[i].size());

        print(nodes);
        print(edge_count);
            
        while(nodes.size()>2){
            vector<int> pop;
            for(vector<int>::iterator iter = nodes.begin(); iter!= nodes.end();){
                if(edge_count[*iter] == 1){
                    pop.push_back(*iter);
                    edge_count[*iter] = 0;
                    iter = nodes.erase(iter);
                } else
                    iter++;
            }
            print(pop);
            for(int i=0; i<pop.size(); i++){
                for(int j=0; j<edge_matrix[pop[i]].size(); j++){
                    edge_count[edge_matrix[pop[i]][j]]--;
                }
            }
            print(edge_count);
        }
        return nodes;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(4, 5));
    vector<int> ret = sol.findMinHeightTrees(6, edges);
    print(ret);
    return 0;
}
