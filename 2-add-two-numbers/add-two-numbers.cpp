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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        int carry = 0;

        while(temp1 != nullptr && temp2 != nullptr){
            int d1 = temp1 -> val;
            int d2 = temp2 -> val;
            int sum = d1 + d2 + carry;\
            if(sum > 9) carry = 1;
            else carry = 0;
            sum = sum % 10;
            result -> next = new ListNode(sum);
            result = result -> next;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        while(temp1 != nullptr){
            int d1 = temp1 -> val;
            int sum = d1 + carry;
            if(sum > 9) carry = 1;
            else carry = 0;
            sum = sum % 10;
            result -> next = new ListNode(sum);
            result = result -> next;
            temp1 = temp1 -> next;
        }
        while(temp2 != nullptr){
            int d1 = temp2 -> val;
            int sum = d1 + carry;
            if(sum > 9) carry = 1;
            else carry = 0;
            sum = sum % 10;
            result -> next = new ListNode(sum);
            result = result -> next;
            temp2 = temp2 -> next;
        }
        if(carry == 1){
            result -> next = new ListNode(1);
        }
        return head -> next;
    }
};