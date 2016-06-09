#include <iostream>
#include <string>
using namespace std;

class Solution {
private:

    inline int max(int a, int b){
	return a>b?a:b;
    }

    inline int min(int a, int b, int c){
	int m = a;
	if(b<m)
	    m = b;
	if(c<m)
	    m = c;
	return m;
    }
    
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
	int size2 = word2.size();
	if(size1 == 0 || size2 == 0)
	    return max(size1, size2);

	int **dp = new int*[size1];
	for(int i=0; i<size1; i++){
	    dp[i] = new int[size2];
	    for(int j=0; j<size2; j++)
		dp[i][j] = 0;
	}
	
	for(int i=0; i<size1; i++)
	    for(int j=0; j<size2; j++){
		if(word1[i] == word2[j]){
		    if(i==0 || j==0)
			dp[i][j] = i+j;
		    else
			dp[i][j] = dp[i-1][j-1];
		} else {
		    int back = i>0&&j>0?dp[i-1][j-1]:i+j;
		    int delete_1 = i>0?dp[i-1][j]:j;
		    int delete_2 = j>0?dp[i][j-1]:i;
		    dp[i][j] = min(back, delete_1, delete_2) + 1;
		}
	    }
	return dp[size1-1][size2-1];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    cout << sol.minDistance("heeh", "haha") << endl;
    return 0;
}
