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
        if(!head) return head;
        ListNode* temp = head;
        int cnt = 1;
        while(temp-> next != nullptr){
            cnt++;
            temp = temp -> next;
        }
        ListNode* tail = temp;
        temp -> next = head;
        int rotations = k % cnt;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0 ; i < rotations ; i++){
            fast = fast -> next;
        }
        while(fast -> next != head){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* newHead = slow -> next;
        slow -> next = nullptr;
        return newHead;
    }
};