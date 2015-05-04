/**
https://leetcode.com/problems/remove-linked-list-elements/

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

*/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        ListNode *cur = head, *pre = NULL;
        ListNode *final_head = head;
        while(cur){
            while(cur && cur->val == val){
                if(!pre){
                    final_head = cur->next;
                    delete cur;
                    cur = final_head;
                }else{
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
            }
            if(cur){
                pre = cur;
                cur = cur->next;
            }

        }
        return final_head;
    }
};

int main()
{
    Solution s;
    s.removeElements(NULL, 0);
    cout << "Hello world!" << endl;
    return 0;
}
