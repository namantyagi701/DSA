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
    ListNode *detectCycle(ListNode *head) {
        // temp = head;
        // ListNode* Node = new ListNode(-1);
        while(head != NULL){
            if(head -> val == INT_MAX) return head;
            head -> val = INT_MAX;
            head = head -> next;
        }
        return NULL;
    }
};