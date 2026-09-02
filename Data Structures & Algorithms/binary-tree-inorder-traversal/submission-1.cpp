/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> iT;
        iTR(iT, root);
        return iT;
    }
    void iTR(vector<int>& iT, TreeNode* node){
        if(!node) return;
        iTR(iT, node->left);
        iT.push_back(node->val);
        iTR(iT, node->right);
    }

};