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
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;

        for(vector<int>::iterator iter = nums.begin()+1;
            iter != nums.end();){
            if(*iter == *(iter-1))
                iter = nums.erase(iter);
            else
                iter++;
        }
        return nums.size();
    }
};

int main(int argc, char *argv[])
{
    
    return 0;
}
