#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const int lengthBit_n = sizeof(n)*8;
		unsigned long tmp;
		int numTmp = n;
        bitset<lengthBit_n> x(numTmp);

		//unsigned long * left = &x[0];
		//unsigned long * right = &x[lengthBit_n-1];
		cout<<sizeof(x)<<endl;
		cout<<sizeof(bitset<lengthBit_n>::reference)<<endl;
		bitset<lengthBit_n>::reference * left = &x[0];
		bitset<lengthBit_n>::reference * right = &x[lengthBit_n-1];
		/*前后交换的思想*/
		for(; left<right ; left++, right--)
        {
            tmp = * left;
            *left = *right;
            *right = tmp;
        }
		int reverse_num = x.to_ulong();

		/*复制的思想*/
		//bitset<lengthBit_n> test;
        /*for(int i=0;i<lengthBit_n;i++)
        {
           test[lengthBit_n-i-1] = x[i];
        }
		int reverse_num = test.to_ulong();*/

		cout<<reverse_num<<endl;
		return reverse_num;
	}
};

int main()
{
	uint32_t n = 9;
	Solution Solver;
	int count = Solver.reverseBits(n);
	std::cout<<n<<" hamming weight is : "<<count<<std::endl;
	system("pause");
}