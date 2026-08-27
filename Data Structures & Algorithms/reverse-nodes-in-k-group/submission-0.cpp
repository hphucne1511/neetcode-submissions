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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur){
            ListNode* left = cur;
            for(int i = 1; i < k; i++){
                if(!cur){
                    break;
                }
                cur = cur->next;
            }
            if(!cur) break;
            ListNode* right = cur;
            cur = cur->next;
            reverse(left, right);
            if(prev) prev->next = right;
            else head = right;
            prev = left;
        }
        return head;
    }
    void reverse(ListNode* left, ListNode* right){
        ListNode* st = left;
        ListNode* en = right->next;
        ListNode* prev = nullptr;
        while(left != right){
            ListNode* temp = left->next;
            left->next = prev;
            prev = left;
            left = temp;
        }
        left->next = prev;
        st->next = en;
    }
};
