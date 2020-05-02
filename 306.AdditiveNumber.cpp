#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  long long getNum(string num, int start, int end) {
    long long n = 0;
    for(int i=start; i<=end; i++) {
      n = n*10+num[i]-'0';
    }
    return n;
  }

  bool additive(string nums, int start) {
    for(int i=start; i<int(nums.size())-2; i++) {
      if(nums[start] == '0' && i-start+1 > 1) {
        continue;
      }

      long long n1 = getNum(nums, start, i);
      for (int j=i+1; j<int(nums.size())-1;j++){
        if(i+1 < nums.size() && nums[i+1] == '0' && j-i > 1) {
          continue;
        }

        long long n2 = getNum(nums, i+1, j);
        for (int k=j+1; k<int(nums.size());k++) {
          if(j+1 < nums.size() && nums[j+1] == '0' && k-j>1) {
            continue;
          }

          int minBits = max(i-start+1, j-i);
          int maxBits = minBits+1;
          if(k-j > maxBits || k-j < minBits){
            continue;
          }

          long long n3 = getNum(nums, j+1, k);
          if(n1 + n2 != n3) {
            continue;
          }
          if(k == nums.size()-1) {
            return true;
          }

          if(additive(nums, i+1)) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool isAdditiveNumber(string num) {
    return additive(num, 0);
  }
};


int main() {
  Solution s;
  cout << s.isAdditiveNumber("101") << endl;

  return 0;
}
