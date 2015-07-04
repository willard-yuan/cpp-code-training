//
//  main.cpp
//  remove-duplicate-from-sorted-list
//
//  Created by willard on 15/6/27.
//  Copyright (c) 2015年 wilard. All rights reserved.
//

/**
 Problem 83:
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 **/

# include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(head == NULL) return NULL;
        ListNode* p;
        p = head;
        while(p->next != NULL){
            if(p->val == p->next->val){
                p->next = p->next->next;
            }
            else{
                p = p->next;
            }
        }
        return head;
    }
};

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
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    print(node1);
    node1 = s.deleteDuplicates(node1);
    print(node1);
}


