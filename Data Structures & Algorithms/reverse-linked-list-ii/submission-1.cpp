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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* bR = nullptr;
        int i = 1;
        while(i < left){
            if(i == left - 1) bR = cur;
            cur = cur->next;
            i++;
        }
        ListNode* eR = cur;
        while(i <= right){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            i++;
        }
        if(left == 1) head = prev;
        else bR->next = prev;
        eR->next = cur;
        return head;
    }
};