#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <assert.h>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        string::size_type pos = haystack.find(needle);
        if(pos == string::npos)
            return -1;
        else
            return (int)pos;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << sol.strStr("asdfdfsdfdsfds", "fdfs") << endl;
    return 0;
}
