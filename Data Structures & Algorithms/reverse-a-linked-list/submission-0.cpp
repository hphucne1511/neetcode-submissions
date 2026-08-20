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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        stack<ListNode*> link;
        while(head->next != nullptr){
            link.push(head);  
            head = head->next;
        } 
        ListNode* cur = head;
        while(!link.empty()){
            cur->next = link.top();
            cur = cur->next;
            link.pop();
        }
        cur->next = nullptr;
        return head;
    }
};
