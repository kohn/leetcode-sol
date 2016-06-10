#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    int max(int a, int b){
	return a>b?a:b;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
	if(s1.size() + s2.size() != s3.size())
	    return false;

	// bool **dp = new bool*[s1.size()+1];
	// for(int i=0; i<=s1.size(); i++){
	//     dp[i] = new bool[s2.size()+1];
	//     for(int j=0; j<=s2.size(); j++)
	// 	dp[i][j] = false;
	// }
	bool dp[s1.size()+1][s2.size()+1] = {false};
	dp[0][0] = true;

	for(int i=0; i<s3.size(); i++){
	    bool flag = false;
	    for(int j=max(-1, i-s2.size()); j<=i&&j<(int)s1.size(); j++){
		if(j >=0 && s3[i] == s1[j] && dp[j][i-j])
		    dp[j+1][i-j] = flag = true;
		if(i-j-1 < s2.size() && i-j-1>=0 && s3[i] == s2[i-j-1] && dp[j+1][i-j-1])
		    dp[j+1][i-j] = flag = true;
	    }
	    if(!flag)
		return false;
	}
	return dp[s1.size()][s2.size()];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << sol.isInterleave("bababbbcabbcacbcbcbbaaabbabbabcccaccabcbcaaacbccab",
			     "bbbcaaabcacbccaabbbaccccccbcbcabbcabaaacbaaccbcccbabac",
			     "bbcbcbbaabbcaabcbccbbcabcbacabcbbbcbaaccccbcbcaaabbbcabcbcababbcaccaabcaacbccaabcacaaaacbabbccccabcbabac") << endl;
    return 0;
}
