import os

class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        self.sum = 0
        n_str = '{0:032b}'.format(n)
        for char in n_str:
            self.sum = self.sum + int(char)
        return self.sum

if __name__ == '__main__':
	Solver = Solution()
	n = 11
	print "%d hamming weight is: %d" %(n, Solver.hammingWeight(n))
	os.system("pause")

        