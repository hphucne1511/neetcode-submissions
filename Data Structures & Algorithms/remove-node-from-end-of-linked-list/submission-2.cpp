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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* cur = head;
        while(cur){
            size++;
            cur = cur->next;
        }
        size -= n;
        if(size == 0) return head->next;
        cur = head;
        while(size > 1){
            cur = cur->next;
            size--;
        }
        cur->next = cur->next->next;
        return head;
    }
};
