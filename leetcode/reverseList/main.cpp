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
    ListNode* reverseList(ListNode* head) {
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
};

int main()
{
    Solution s;
    s.reverseList(NULL);

    return 0;
}
