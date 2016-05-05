class Solution:
    def reverseBits(self, n):
        res = 0
        for i in range(32):
            res = (res<<1) + n%2
            n = n >> 1
        return res

if __name__ == '__main__':
    s = Solution()
    print s.reverseBits(1)
    print s.reverseBits(43261596)             #964176192
