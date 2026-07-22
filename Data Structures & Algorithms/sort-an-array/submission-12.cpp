struct node{
    int data;
    node* left;
    node* right;
    int balanceFactor;
    node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class AVL{
public:
    node* root;
    AVL() : root(nullptr) {}
    node* leftRotate(node* root){
        node* newNode = root->right;
        node* temp = newNode->left;
        newNode->left = root;
        root->right = temp;
        return newNode;
    }
    node* rightRotate(node* root){
        node* newNode = root->left;
        node* temp = newNode->right;
        newNode->right = root;
        root->left = temp;
        return newNode;
    }
    void insert(int num){
        bool taller = false;
        root = insert(root, num, taller);
    }
    node* insert(node* root, int num, bool& taller){
        if(root == nullptr){
            root = new node(num);
            taller = true;
            root->balanceFactor = 0;
            return root;
        }
        if(num <= root->data){
            root->left = insert(root->left, num, taller);
            if(taller){
                if(root->balanceFactor == 0) root->balanceFactor = -1;
                else if(root->balanceFactor == -1){
                    if(root->left->balanceFactor == -1){
                        root = rightRotate(root);
                        root->balanceFactor = 0;
                        root->right->balanceFactor = 0;
                    }else{
                        int rightBf = root->left->right->balanceFactor;
                        root->left = leftRotate(root->left);
                        root = rightRotate(root);
                        if(rightBf == 0){
                            root->left->balanceFactor = 0;
                            root->right->balanceFactor = 0;
                        }else if(rightBf == -1){
                            root->left->balanceFactor = 0;
                            root->right->balanceFactor = 1;
                        }else{
                            root->left->balanceFactor = -1;
                            root->right->balanceFactor = 0;
                        }
                        root->balanceFactor = 0;
                    }
                    taller = false;
                }else{
                    root->balanceFactor = 0;
                    taller = false;
                }
            }
        }
        else if(num > root->data){
            root->right =insert(root->right, num, taller);
            if(taller){
                if(root->balanceFactor == 0) root->balanceFactor = 1;
                else if(root->balanceFactor == 1){
                    if(root->right->balanceFactor == 1){
                        root = leftRotate(root);
                        root->balanceFactor = 0;
                        root->left->balanceFactor = 0;
                    }else{
                        int leftBf = root->right->left->balanceFactor;
                        root->right = rightRotate(root->right);
                        root = leftRotate(root);
                        if(leftBf == 0){
                            root->left->balanceFactor = 0;
                            root->right->balanceFactor = 0;
                        }else if(leftBf == -1){
                            root->left->balanceFactor = -1;
                            root->right->balanceFactor = 0;
                        }else{
                            root->left->balanceFactor = 0;
                            root->right->balanceFactor = -1;
                        }
                        root->balanceFactor = 0;
                    }
                    taller = false;
                }else{
                    root->balanceFactor = 0;
                    taller = false;
                }
            }
        }
        return root;
    }
    void inorder(node* root, vector<int>& ans){
        if(root == nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        AVL avlTree;
        for(int num : nums){
            avlTree.insert(num);
        }
        vector<int> ans;
        avlTree.inorder(avlTree.root, ans);
        return ans;
    }
};