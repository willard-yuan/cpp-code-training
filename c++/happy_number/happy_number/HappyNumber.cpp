#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
	int addSum(int n)
	{
		int sum = 0,d =0,flag = 0, n1= n;
		while(n1)
		{
			n1/=10;
			flag++;
		}
		for(int i=flag;i>0;i--)
		{
			d = n%10;
			n/=10;
			sum = sum+d*d;
		}
		return sum;
	}

    bool isHappy(int n)
	{
		set<int>SqList;
		int sumTmp = addSum(n);
        while(sumTmp!=1&&SqList.find(sumTmp)==SqList.end())
        {
			SqList.insert(sumTmp);
			sumTmp = addSum(sumTmp);
        }
		if (sumTmp ==1)
			return true;
		else
			return false;
    }
};

int main()
{
	int n = 19;
	Solution solver;
	bool str = solver.isHappy(n);
	cout<<n<<" is "<<str<<endl;
	system("pause");
}