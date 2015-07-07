// 面试题5：从尾到头打印链表，p51

# include <iostream>
# include <stack>
using namespace std;

struct listNode{
	int m_nkey;
	listNode *m_pNext;
	listNode(int x) : m_nkey(x), m_pNext(NULL) {}
};

void print_list_reversingly_iteratively(listNode *pHead){
	stack<listNode *> nodes;
	listNode *pNode = pHead;
	while(pNode != NULL){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while(!nodes.empty()){
		pNode = nodes.top();
		cout << pNode->m_nkey << " ";
		nodes.pop();
	}
	cout << endl;
}

int main(){
	listNode *node1 = new listNode(4);
	listNode *node2 = new listNode(3);
	listNode *node3 = new listNode(2);
	listNode *node4 = new listNode(1);
	node1->m_pNext = node2;
	node2->m_pNext = node3;
	node3->m_pNext = node4;
	print_list_reversingly_iteratively(node1);
	system("pause");
}
