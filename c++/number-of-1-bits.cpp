#include <bitset>
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
		int tmp = n;
        std::bitset<sizeof(n)*8> x(tmp);
        for (int i=0;i<sizeof(x)*8;i++)
        {
            if (x[i]==1)
            ++count;
        }
        return count;
    }
};

int main()
{
	uint32_t n = 11;
	Solution Solver;
	int count = Solver.hammingWeight(n);
	std::cout<<n<<" hamming weight is : "<<count<<std::endl;
	system("pause");
}