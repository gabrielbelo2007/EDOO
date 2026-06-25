#include <iostream>
using namespace std;

class TreeNode{

    public:
        int key;
        char element;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int key){
            this->key = key;
            this->left = this->right = nullptr;
        }
};

class BST{

    private:
        TreeNode* root;
        int nodecount;

        char findhelp(TreeNode* root, int key){
            if(root == nullptr) return ' ';

            if(root->key > key){
                return findhelp(root->left, key);
            }

            else if(root->key < key){
                return findhelp(root->right, key);
            }

            else{
                return root->element;
            }
        }

        TreeNode* getmin(TreeNode* root){
            if(root->left == nullptr) return root;
            return getmin(root->left);
        }

        TreeNode* deletemin(TreeNode* root){
            if(root->left == nullptr) return root->right;
            root->left = deletemin(root->left);
            return root;
        }

        TreeNode* removehelp(TreeNode* root, int key){
            if(root == nullptr) return nullptr;

            if(root->key > key){
                root->left = removehelp(root->left, key);
            }

            else if(root->key < key){
                root->right = removehelp(root->right, key);
            }

            else{

                if(root->left == nullptr){
                    return root->right;
                }

                else if(root->right == nullptr){
                    return root->left;
                }

                else{
                    TreeNode* temp = getmin(root->right);
                    root->element = temp->element;
                    root->key = temp->key;
                    root->right = deletemin(root->right);
                }
            }

            return root;
        }

        TreeNode* inserthelp(TreeNode* root, int key){
            if(root == nullptr) return new TreeNode(key);

            if(root->key > key){
                root->left = inserthelp(root->left, key);
            }

            else{
                root->right = inserthelp(root->right, key);
            }

            return root;
        }

        void preorderhelp(TreeNode* root){
            if(root != nullptr){
                cout << root->key << " ";
                preorderhelp(root->left);
                preorderhelp(root->right);
            }
        }

        void inorderhelp(TreeNode* root){
            if(root != nullptr){
                inorderhelp(root->left);
                cout << root->key << " ";
                inorderhelp(root->right);
            }
        }

        void postorderhelp(TreeNode* root){
            if(root != nullptr){
                postorderhelp(root->left);
                postorderhelp(root->right);
                cout << root->key << " ";
            }
        }

    public:

        BST(){
            this->root = nullptr;
        }

        char remove(int key){
            char temp = find(key);

            if (temp != ' '){
                this->root = removehelp(this->root, key);
                nodecount--;
            }
            return temp;
        }

        char find(int key){
            return findhelp(this->root, key);
        }

        void insert(int key){ // char element
            this->root = inserthelp(this->root, key);
            this->nodecount++;
        }

        void preorder(){
            preorderhelp(this->root);
        }

        void inorder(){
            inorderhelp(this->root);
        }

        void postorder(){
            postorderhelp(this->root);
        }
};

int main(){

    int operacoes;
    cin >> operacoes;

    BST bst;
    for(int operacao = 0; operacao < operacoes; operacao++){

        string comando;
        int key;
        cin >> comando;

        if(comando == "insert"){
            cin >> key;
            bst.insert(key);
        }

        else{
            if(comando == "pre"){
                bst.preorder();
                cout << "\n";
            }

            else if(comando == "in"){
                bst.inorder();
                cout << "\n";
            }

            else{ // post
                bst.postorder();
                cout << "\n";
            }
        }

    }

    return 0;
}