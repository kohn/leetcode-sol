#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int jump(int A[], int n) {
        int a[100000];
        a[0] = 0;
        int last_deal = 0;
        for(int i=0; i<n;i++){
            int cover_range = A[i]+i;
            for(int j=last_deal+1; j<=cover_range; j++){
                a[j] = a[i] + 1;
            }
            last_deal = last_deal>cover_range?last_deal:cover_range;
        }
        return a[n-1];
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    int num = 1000;
    int* a = new int[num];
    for(int i=0; i<num;i++)
        a[i] = 1;
    int b[] = {2,3,1,1,4};
    //cout<<s.jump(b, 5)<<endl;
    cout<<s.jump(a, num)<<endl;
    return 0;
}
