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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1-> val >= ptr2 -> val) {
                ListNode* node = new ListNode(ptr2->val);
                temp->next = node;
                temp = node;
                ptr2 = ptr2 -> next;
            } else {
                ListNode* node = new ListNode(ptr1->val);
                temp->next = node;
                temp = node;
                ptr1 = ptr1 -> next;
            }
        }
        if(ptr1 == nullptr){
            temp -> next = ptr2;
        }
        else{
            temp -> next = ptr1;
        }
        return head -> next;
    }
};