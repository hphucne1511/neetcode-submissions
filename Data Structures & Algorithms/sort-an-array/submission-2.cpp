struct node{
    int data;
    node* left;
    node* right;
    node(int num, node* fath) : data(num), left(nullptr), right(nullptr) {}
};

class BST {
public:
    node* root;
    BST() : root(nullptr) {}
    void insert(int num){
        node* temp = root;
        if(root == nullptr) root = new node(num, nullptr);
        else{
            while(temp != nullptr){
                if(num < temp->data){
                    if(temp->left == nullptr){
                        temp->left = new node(num, temp);
                        break;
                    } 
                    else temp = temp->left;
                }else{
                    if(temp->right == nullptr){
                        temp->right = new node(num, temp);
                        break;
                    } 
                    else temp = temp->right;
                }
            }
        }
    }
    void inorder(node* root, vector<int>& ans){
        if(root == nullptr) return;
        node* curr = root;
        //inorder(root->left, ans);
        //ans.push_back(root->data);
        //inorder(root->right, ans);
        stack<node*> st;
        while(curr != nullptr || !st.empty()){
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();

            ans.push_back(curr->data);

            curr = curr->right;
        }
    }
};



class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        BST binarySearchTree;
        for(int num : nums) binarySearchTree.insert(num);
        vector<int> ans;
        binarySearchTree.inorder(binarySearchTree.root, ans);
        return ans;
    }
};