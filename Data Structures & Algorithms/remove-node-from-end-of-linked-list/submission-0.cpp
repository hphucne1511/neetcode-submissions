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
        ListNode* cur = head;
        vector<ListNode*> nodes;
        while(cur){
            nodes.push_back(cur);
            cur = cur->next;
        }
        int idx = nodes.size() - n;
        ListNode* temp;
        if(idx == 0){
            head = head->next;
        }else{
            cur = nodes[idx - 1];
            cur->next = cur->next->next;
        }
        return head;

    }
};
