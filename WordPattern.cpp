#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void split(vector<string> &v, string &str){
        int last = -1;
        for(int i=0; i<str.size(); i++){
            if(str[i] == ' '){
		string tmp = str.substr(last+1, i-last-1);
                v.push_back(tmp);
                last = i;
            }
        }
	int i = str.size();
	v.push_back(str.substr(last+1, i-last-1));
    }
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        split(words, str);
	for(auto w : words)
	    cout << w << endl;
        string ch_map[26];
        map<string, bool> mapped;
        if(words.size() != pattern.size())
            return false;
        for(int i=0; i<pattern.size(); i++){
            if(ch_map[pattern[i]-'a'] == ""){
                if(mapped.find(words[i]) == mapped.end()){
                    ch_map[pattern[i]-'a'] = words[i];
                    mapped[words[i]] = true;
                } else{
                    return false;
                }
            } else{
                if(ch_map[pattern[i]-'a'] != words[i])
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    cout << sol.wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}

