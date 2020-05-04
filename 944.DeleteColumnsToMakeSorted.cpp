class Solution {
public:
  int minDeletionSize(vector<string>& A) {
    if(A.size() == 0) {
      return 0;
    }
        
    int length = A[0].size();
    int count = 0;
    for(int i=0; i<length; i++) {
      for (int j=1; j<A.size(); j++) {
        if(A[j][i] < A[j-1][i]) {
          count++;
          break;
        }
      }
    }
    return count;
  }
};
