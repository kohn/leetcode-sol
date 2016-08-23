#include <iostream>
#include <string>
using namespace std;

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
    string key(string s){
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hashtable;
        for(auto &s : strs){
            hashtable[key(s)].push_back(s);
        }
        vector<vector<string>> ret;
        for(auto iter=hashtable.begin(); iter!=hashtable.end(); iter++){
            ret.push_back(iter->second);
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}
