/*
https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.

Too simple !!!
*/
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        return reverseList_recursively(head);
    }

private:
    ListNode* reverseList_iteratively(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *pre =NULL, *cur = head;

        while(cur != NULL){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseList_recursively(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode *final_head = reverseList_recursively(head->next);

        head->next->next = head;
        head->next = NULL;

        return final_head;
    }
};

int main()
{
    Solution s;
    s.reverseList(NULL);

    return 0;
}
