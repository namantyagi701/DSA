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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
          temp = temp->next;
          count++;
          if(count > 2) break;
        }
        if(count <= 2) return head;

        ListNode* h1 = head;
        ListNode* h2 = head -> next;
        ListNode*even = h2;
        while(h2 !=  NULL && h1 -> next -> next != NULL && h1 != NULL){
           h1 -> next = h1 -> next -> next;
           h1 = h2 -> next;
           h2 -> next = h1 -> next;
           h2 = h1 -> next;
        }
        h1 -> next = even;
        return head;
    }
};