#include <iostream>
using namespace std;

class TreeNode{

    public:
        int key;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int key){
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class BST{

    private:
        TreeNode* root;
        int nodecount;

        bool findhelp(TreeNode* root, int key){
            if (root == nullptr) return false;

            if (root->key > key){
                return findhelp(root->left, key);
            }

            else if (root-> key < key){
                return findhelp(root->right, key);
            }

            else{
                return true;
            }

        }

        TreeNode* inserthelp(TreeNode* root, int key){
            if (root == nullptr) return new TreeNode(key);

            if (root->key > key){
                root->left = inserthelp(root->left, key);
            }

            else{
                root->right = inserthelp(root->right, key);
            }

            return root;
        }

        void preorder_recursive(TreeNode* root){
            if(root != nullptr){
                cout << " " << root->key;
                preorder_recursive(root->left);
                preorder_recursive(root->right);
            }
        }

        void inorder_recursive(TreeNode* root){
            if(root != nullptr){
                inorder_recursive(root->left);
                cout << " " << root->key ;
                inorder_recursive(root->right);
            }
        }

        void postorder_recursive(TreeNode* root){
            if(root != nullptr){
                postorder_recursive(root->left);
                postorder_recursive(root->right);
                cout << " " << root->key;
            }
        }

    public:

        BST(){
            this->root = nullptr;
            this->nodecount = 0;
        }

        int find(int key){
            return findhelp(this->root, key);
        }

        void insert(int key){
            this->root = inserthelp(this->root, key);
            nodecount++;
        }
        
        void preorder(){
            preorder_recursive(this->root);
        }

        void inorder(){
            inorder_recursive(this->root);
        }

        void postorder(){
            postorder_recursive(this->root);
        }

};

int main(){

    int lines;
    cin >> lines;

    BST bst;
    for(int line = 0; line < lines; line++){

        int num;
        cin >> num;
        
        bst.insert(num);
    }

    cout << "Pre order :";
    bst.preorder();
    cout << endl;

    cout << "In order  :";
    bst.inorder();
    cout << endl;

    cout << "Post order:";
    bst.postorder();
    cout << endl;

    return 0;
}