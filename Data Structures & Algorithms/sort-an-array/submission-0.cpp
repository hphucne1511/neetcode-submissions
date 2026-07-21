struct node{
    int data;
    node* left;
    node* right;
    node* father;
    node(int num, node* fath) : data(num), left(nullptr), right(nullptr), father(fath) {}
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
    void inorder(node* nod, vector<int>& ans){
        if(nod == nullptr) return;
        
        inorder(nod->left, ans);
        ans.push_back(nod->data);
        inorder(nod->right, ans);
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