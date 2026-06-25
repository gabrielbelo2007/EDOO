#include <iostream>
#include <string>
#include <stack>
using namespace std;

class TreeNode{

    public:
        char key;
        TreeNode* left;
        TreeNode* right;

        TreeNode(char key){
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
        }

};

class BST{

    private:
        TreeNode* root;

        TreeNode* inserthelp(TreeNode* root, char key){
            if(root == nullptr) return new TreeNode(key);

            if(root->key > key){
                root->left = inserthelp(root->left, key);
            }

            else{
                root->right = inserthelp(root->right, key);
            }

            return root;
        }

        void preorder_recursive(TreeNode* root){
            if(root != nullptr){
                cout << root->key;
                preorder_recursive(root->left);
                preorder_recursive(root->right);
            }
        }

    public:
        
        BST(){
            this->root = nullptr;
        }

        void insert(char key){
            this->root = inserthelp(this->root, key);
        }

        void preorder(){
            preorder_recursive(this->root);
            cout << endl;
        }
};

int main(){

    string line;
    stack<string> array_leaves;
    do
    {  
        cin >> line;
        if(line != "*" && line != "$"){
            array_leaves.push(line);
        }

        else{
            BST bst;

            while(!array_leaves.empty()){

                for(char letter : array_leaves.top()){
                    bst.insert(letter);
                }
                array_leaves.pop();
            }

            bst.preorder();
        }

    } while (line != "$");

    return 0;
}