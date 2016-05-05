class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        count = 0
        while n>0:
            count += n%2
            n /=2
        return count
            


if __name__ == '__main__':
    s = Solution()
    print s.hammingWeight(10)             #2
    print s.hammingWeight(1)              #1
    print s.hammingWeight(0)              #0
    print s.hammingWeight(11)             #3
