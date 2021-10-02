#include<iostream>

struct Node{
    int val;
    Node* left;
    Node* right;
};

Node* create_node(int data){
    Node* temp = new Node;
    temp->val = data;
    temp->left = temp->right = nullptr;
    return temp;
}

void insert(int data,Node* root){
    // if the value of the root node is greater than
    // value of data to be inserted then we go in
    // left subtree
    if(root->val > data){
        if(root->left != nullptr){
            insert(data,root->left);
        }
        else{
            root->left=create_node(data);
        }
    }
    // if the value of the root node is lesser than
    // value of data to be inserted then we go in
    // right subtree
    if(root->val < data){
        if(root->right != nullptr){
            insert(data,root->right);
        }
        else{
            root->right=create_node(data);
        }
    }
}

void preorder_traversal(Node* root){  
    std::cout<<root->val<<" ";

    if(root->left!=nullptr){
        preorder_traversal(root->left);
    }
    if(root->right!=nullptr){
        preorder_traversal(root->right);
    }
    delete root;
}

int main(){
    Node* root = create_node(5);
    insert(3,root);
    insert(4,root);
    insert(1,root);
    insert(8,root);
    insert(7,root);

    /* tree looks like
              5
            /   \  
           3     8
          / \    /
         1   4  7
         Preorder Traversal for the following tree looks like:
         -> 5 3 1 4 8 7
    */

    preorder_traversal(root);
    return 0;
    // Time Complexity   : O(n)
    // Space Complexity  : O(1)   
}
