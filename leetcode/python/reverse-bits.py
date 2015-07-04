import os

class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        n_str = '{0:032b}'.format(n)
        reversedStr = n_str[::-1]
        reversedNum = int(reversedStr,2)
        return reversedNum

if __name__ == '__main__':
	Solver = Solution()
	n = 43261596
	print "%d afer reversing the number is: %d" %(n, Solver.reverseBits(n))
	os.system("pause")

        