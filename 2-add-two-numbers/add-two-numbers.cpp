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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* point = temp;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = (l1-> val) + (l2 -> val) + carry;
            if(sum > 9) carry = 1;
            else carry = 0;
            if(sum > 9) sum = sum % 10;
            ListNode* node = new ListNode(sum);
            temp -> next = node;
            temp = node;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != NULL){
            int sum = carry + (l1 -> val);
            if(sum > 9) carry = 1;
            else carry = 0;
            if(sum > 9) sum = sum % 10;
            ListNode* node = new ListNode(sum);
            temp -> next = node;
            temp = node;
            l1 = l1 -> next;
        }
        while(l2 != NULL){
            int sum = carry + (l2-> val);
            if(sum > 9) carry = 1;
            else carry = 0;
            if(sum > 9) sum = sum % 10;
            ListNode* node = new ListNode(sum);
            temp -> next = node;
            temp = node;
            l2 = l2 -> next; 
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            temp -> next = node;
        }
        return point -> next;
    }
};