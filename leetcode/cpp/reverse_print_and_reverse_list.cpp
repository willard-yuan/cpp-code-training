/*输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        std::vector<int> res;
        if (head == NULL) return res;
        ListNode* p = head;
        stack<int> tmp_stack;
        while(p) {
            tmp_stack.push(p->val);
            p = p->next;
        }
        while(! tmp_stack.empty()) {
            int tmp_value = tmp_stack.top();
            tmp_stack.pop();
            res.push_back(tmp_value);
        }
        return res;
    }
};

/*206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：
输入：head = [1,2]
输出：[2,1]
示例 3：
输入：head = []
输出：[]
提示：
链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 双指针方式
        ListNode* cur = NULL;
        ListNode* pre = head;
        while(pre != NULL) {
            ListNode* tmp_node = pre->next;
            pre->next = cur;
            cur = pre;
            pre = tmp_node;
        }
        return cur;
    }
};
