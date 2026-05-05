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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == nullptr || head -> next == nullptr || k == 0) return head;
       int n = 0;
       ListNode*temp = head;
       while(temp != nullptr){
        n++;
        temp = temp-> next;
       }
       k = k % n;
       if (k == 0) return head;
       int nodes = n-k-1;
       temp = head;
       while(nodes){
       temp = temp->next;
       nodes--;
       } 
       ListNode *NewHead = temp->next;
       temp->next = nullptr;
       ListNode *temp2 = NewHead;
       while(temp2->next != nullptr){
        temp2 = temp2->next;
       }
       temp2->next = head;
       return NewHead;
    }
};