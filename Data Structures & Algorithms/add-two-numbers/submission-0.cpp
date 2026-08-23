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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool c = false;
        ListNode* sumHead = new ListNode;
        ListNode* cur = sumHead;
        bool flag = true;
        while(l1 || l2){
            int sum = 0;
            if(l1 && l2)
                sum = l1->val + l2->val;
            else if(l1) sum = l1->val;
            else if(l2) sum = l2->val;
            if(c){
                sum++;
                c = false;
            }
            if(sum >= 10){
                sum -= 10;
                c = true;
            }
            if(flag){
                cur->val = sum;
                flag = false;
            }else{
                cur->next = new ListNode(sum);
                if(l1 || l2) cur = cur->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
        }
        if(c) cur->next = new ListNode(1);
        return sumHead;
    }
};
