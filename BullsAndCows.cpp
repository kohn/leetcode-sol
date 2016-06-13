#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int size = secret.size();
        int *status = new int[10];
        int bull = 0;
        int cow = 0;
	for(int i=0; i<10; i++)
	    status[i] = 0;
        for(int i=0; i<size; i++){
            status[secret[i]-'0'] += 1;
        }
        
        for(int i=0; i<size; i++){
            int digit = guess[i]-'0';
            if(secret[i] == guess[i]){
                bull++;
                status[digit] -= 1;
            } 
        }
        
        for(int i=0; i<size; i++){
            if(secret[i] == guess[i])
                continue;
            int digit = guess[i] - '0';
            if(status[digit] > 0){
                status[digit]--;
                cow++;
            }
        }
        char ch[1024] = {0};
        sprintf(ch, "%dA%dB", bull, cow);
        return string(ch);
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    cout << sol.getHint("33000186961121594465", "92206680001903483735") << endl;
    return 0;
}
