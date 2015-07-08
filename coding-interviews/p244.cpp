//  成员列表的初始化顺序与初始化列表的顺序无关，只与在类中声明的顺序有关。
//  该题中先用n2+2去初始化n1，但此时n2并没有初始化，所以n1的结果是随机的；
//  此后用0初始后n2，所以n2输出的是0
# include <iostream>
using namespace std;

class A{
private:
	int n1;
	int n2;
public:
	A(): n2(0), n1(n2+2){}
	void print(){
		cout << "n1: " << n1 << ", n2: " << n2 << endl;
	}
};

int main(){
	A a;
	a.print();
	system("pause");
	return 0;
}

// excute result: n1: -858993458, n2: 0
