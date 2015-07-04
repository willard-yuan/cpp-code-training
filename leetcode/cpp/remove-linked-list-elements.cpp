#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {} //构造函数初始化列表 http://www.cnblogs.com/bluetzar/articles/1223169.html
  };

/*方案一：用一个指针*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		///*第一个while用于解决下面这个问题
		//Input:	[1], 1
		//Output:	{1}
		//Expected:	{}
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }
		if (head == NULL) return NULL;
        ListNode *p;
		p = head;
		while(p->next!=NULL)
		{
			if(p->next->val==val)
			{
				p->next=p->next->next;
			}
			else
				p=p->next;
		}
		return head;
    }
};


/*方案二：用两个指针
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }
		if (head == NULL) return NULL;
        ListNode* prevPoint = head; // empty header
        ListNode* curPoint  = head->next; // the first valid node
        while(curPoint != NULL) {
            if(curPoint->val == val) { 
                prevPoint->next = curPoint->next; // unlink the node you remove
            }
            else {
                prevPoint = curPoint; 
                }
            curPoint = curPoint->next; // go to next value
        }
        return head;
    }
};*/

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout<<head->val;
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    Solution s;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    print(node1);
    node1 = s.removeElements(node1, 2);
    print(node1);
	system("pause");
}
