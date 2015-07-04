#include <bitset>
#include <iostream>
#include <cstdint>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool isIsomorphic(string s, string t)
	{
		unordered_map<char, int> ms, mt;
		for(int i = 0; i < s.size(); ++ i)
		{
			char x = s[i];
			char y = t[i];
			if(ms[s[i]] != mt[t[i]])
				return false;
			ms[s[i]] = mt[t[i]] = i + 1;
		}
		return true;
	}
};

int main()
{
	string s = "egg";
	string t = "foo";
	Solution Solver;
	bool isomorphic;
	isomorphic = Solver.isIsomorphic(s,t);
	std::cout<<s<<" "<<"and"<<" "<<t<<" is isomorphic : "<<isomorphic<<std::endl;
	system("pause");
}
