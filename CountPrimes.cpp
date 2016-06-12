class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        bool *isPrime = new bool[n];
        for(int i=0; i<n; i++)
            isPrime[i] = true;
        int count = 0;
        for(int i=2; i*i<n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<n; j=j+i){
                    isPrime[j] = false;
                }
            }
        }
        for(int i=2; i<n; i++)
            if(isPrime[i])
                count++;
        return count;
    }
};
