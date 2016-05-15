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
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();

        for(vector<int>::iterator iter = nums.begin();
            iter != nums.end();){
            if(*iter == val)
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
