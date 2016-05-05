#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(version1 != "" && version2 != ""){
            int v1 = getVersion(version1);
            int v2 = getVersion(version2);
            if(v1 > v2)
                return 1;
            else if(v1 < v2)
                return -1;
        }
        if(version1 != "" && getVersion(version1) != 0)
            return 1;
        else if(version2 != "" && getVersion(version2) != 0)
            return -1;
        else
            return 0;
    }

private:
    int getVersion(string &version){
        int v = 0;
        int i;
        int length = version.length();
        for (i = 0; i<length; ++i) {
            if(version[i] == '.'){ 
                break;
            }
        }
        string num = version.substr(0, i);
        if (i==length) {
            version = "";
        }
        else{
            version = version.substr(i+1);
        }
        return atoi(num.c_str());
    }

};
int main(int argc, char *argv[])
{
    Solution s;
    string s1="1.2";
    std::cout << s.compareVersion("1", "1.0")<<endl;
    return 0;
}
