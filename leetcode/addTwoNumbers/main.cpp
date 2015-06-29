/*
https://leetcode.com/problems/add-two-numbers/

You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        else if(!l2)
            return l1;

        ListNode *l1_ptr = l1, *l2_ptr = l2;
        ListNode *sum = NULL, *p = NULL;
        int carry = 0;

        while(l1_ptr && l2_ptr){
            int t = l1_ptr->val + l2_ptr->val + carry;
            ListNode *tmp = new ListNode(t%10);
            if(!p){
                sum = tmp;
                p = tmp;
            }else{
                p->next = tmp;
                p = tmp;
            }
            carry = t/10;
            l1_ptr = l1_ptr->next;
            l2_ptr = l2_ptr->next;
        }

        while(l1_ptr){
            int t = l1_ptr->val + carry;
            ListNode *tmp = new ListNode(t%10);
            p->next = tmp;
            p = tmp;
            carry = t/10;
            l1_ptr = l1_ptr->next;
        }

         while(l2_ptr){
            int t = l2_ptr->val + carry;
            ListNode *tmp = new ListNode(t%10);
            p->next = tmp;
            p = tmp;
            carry = t/10;
            l2_ptr = l2_ptr->next;
        }

        if(carry)
            p->next = new ListNode(carry);

        return sum;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
