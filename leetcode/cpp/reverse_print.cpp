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
