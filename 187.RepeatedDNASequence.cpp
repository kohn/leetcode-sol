#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <bitset>
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
    int toInt(string &s, int start_pos){
        int ret = 0;
        for(int i=0; i<10; i++)
            ret = (ret << 2) + (s[start_pos+i]-'A'+1)%5; // (ACGT-A+1)%5之后正好是1,3,2,0, 避免了switch
        return ret;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        bitset<0x00100000> b;
        bitset<0x00100000> saved;
        vector<string> ret;
        if(s.size() < 10)
            return ret;

        int code = toInt(s, 0);
        b[code] = true;
        for(int j=10; j<s.size(); j++){
            code = (((code << 2)+(s[j]-'A'+1)%5) & (0x000FFFFF));
            if(b[code]){
                if(!saved[code]){
                    ret.push_back(s.substr(j-9, 10));
                    saved[code] = true;
                }
            }
            else
                b[code] = true;
        }
        return ret;
    }
};


/**
 * 直觉上认为用数组而不是bitset, 能够通过多用了4倍空间而减少bitset的计算开销,
 * 但是实际上跑出来反而更慢一点点.
 */
// class Solution {
// public:
//     int toInt(string &s, int start_pos){
//         int ret = 0;
//         for(int i=0; i<10; i++)
//             ret = (ret << 2) + (s[start_pos+i]-'A'+1)%5;
//         return ret;
//     }
    
//     vector<string> findRepeatedDnaSequences(string s) {
//         int exist[1<<20] = {0};
//         vector<string> ret;
//         if(s.size() < 10)
//             return ret;
//         int code = toInt(s, 0);
//         exist[code] = true;
//         for(int j=10; j<s.size(); j++){
//             code = (((code << 2)+(s[j]-'A'+1)%5) & (0x000FFFFF));
//             if(exist[code] == 1)
//                 ret.push_back(s.substr(j-9, 10));
//             exist[code]++;
//         }
//         return ret;
//     }
// };


int main(int argc, char *argv[]) {
    Solution sol;
    // vector<string> ret = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    vector<string> ret = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    // vector<string> ret = sol.findRepeatedDnaSequences("AAAAAAAAAA");
    for(auto &s : ret)
        cout << s << endl;
    return 0;
}
