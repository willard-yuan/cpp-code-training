# include <iostream>

using namespace std;

class node{
public:
	int data;
	node *next;
	node(int x): data(x),next(NULL){} //构造函数初始化成员列表 http://www.cnblogs.com/bluetzar/articles/1223169.html
};

//打印链表
void print(node *head){
	for(node *p = head; p != NULL; p = p->next)
		cout<<p->data<<" ";
	cout<<endl;
	cout<<endl;
}

//获取链表长度
int linkLength(node *head){
	int length = 0;
	while(head != NULL){
		head = head->next;
		length++;
	}
	return length;
}

//删除链表中的元素
node* removeElements(node *head, int val){
	//如果链表元素为空，则返回NULL
	if(head == NULL) return NULL;
	//如果删除的元素为链表表头的值
	if(NULL != head && head->data == val) //head != NULL提示警告
		head = head->next;
	node *p = head;
	while(p->next != NULL){
		if(p->next->data == val){
			p->next = p->next->next;
		}
		else{
			p = p->next;
		}
	}
	return head;
}

int main(){
	node *node1 = new node(1); 
	node *node2 = new node(2);
	node *node3 = new node(1);
	node *node4 = new node(4);
	node1->next = node2; //node1为头结点head
	node2->next = node3;
	node3->next = node4;

	cout<<"原链表:"<<endl;
	print(node1); //打印链表

	int linkLen = linkLength(node1); //获取链表长度

	node *node0 = removeElements(node1, 2);
	cout<<"删除元素后的链表:"<<" "<<linkLen<<endl;
	print(node0); //打印删除元素后的链表

	cout<<"link length is:"<<" "<<linkLen<<endl;
	system("pause");
}
