#include <iostream>

using namespace std;

class BST{

    int data;
    BST *left, *right;

public:
    BST();
    BST(int data_val);
    BST* insert(BST* root, int key);
    void Inorder(BST* root);
};

BST:: BST(): data{0}, left{nullptr}, right{nullptr}{
}

BST:: BST(int data_val): data{data_val}, left{nullptr}, right{nullptr}{

}

BST* BST::insert(BST* root, int key){
    if(root == nullptr)
        return new BST(key);

    if(key < root->data){
        root->left = insert(root->left, key);
    }else{
        root->right = insert(root->right, key);
    }
    return root;
}

void BST::Inorder(BST* root){
    if (root == nullptr)
        return;
    Inorder(root->left);
    cout << " " << root->data;
    Inorder(root->right);
}
int main()
{

    BST b, *root = nullptr;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    b.Inorder(root);
    return 0;
}
