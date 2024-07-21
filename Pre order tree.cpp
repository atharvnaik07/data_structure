#include <iostream>

using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform pre-order traversal of a binary tree
void preorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    
    // Visit the current node
    cout << root->val << " ";
    
    // Traverse left subtree
    preorderTraversal(root->left);
    
    // Traverse right subtree
    preorderTraversal(root->right);
}

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    // Deleting the tree to free memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
