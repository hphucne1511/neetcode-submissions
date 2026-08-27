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
    struct cp{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cp> pq;
        for(ListNode* node : lists){
            if(node)
                pq.push(node);
        }
        ListNode* dummy = new ListNode(-10001);
        ListNode* cur = dummy;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            cur->next = temp;
            cur = cur->next;
            pq.pop();
            if(temp->next) pq.push(temp->next);
        }
        return dummy->next;
    }
};
