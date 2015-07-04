import os

class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        while (head != None) and (head.val == val):
            head = head.next
        if head == None:
            return None
        pre = head
        cur = head.next
        while cur != None:
            if cur.val == val:
                pre.next = pre.next.next
            else:
                pre = pre.next
            cur = cur.next

        return head

def printList(head):
    # @param {ListNode} head
    while head != None:
        print(head.val, end = ' ')
        head = head.next
    print() # print '\n'

if __name__ == '__main__':
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(1)
    node4 = ListNode(2)
    node1.next = node2
    node2.next = node3
    node3.next = node4

    printList(node1) # print the origin list
    Solver = Solution();
    node1 = Solver.removeElements(node1, 1)
    printList(node1) # print the result list

        