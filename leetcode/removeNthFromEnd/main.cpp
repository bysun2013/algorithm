/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n <= 0)
            return NULL;

        ListNode *postn, *cur, *pre;
        pre = NULL;
        cur = postn = head;
        for(int i = 1; i < n;i++){
                postn = postn->next;
                if(!postn)
                    return NULL;
        }

        while(postn->next != NULL){
            postn = postn->next;
            pre = cur;
            cur = cur->next;
        }

        if(pre == NULL){
            ListNode *n = head->next;
            delete head;
            return n;
        }else{
            pre->next = cur->next;
            return head;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
