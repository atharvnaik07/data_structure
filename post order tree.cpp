#include <iostream>
using namespace std;

// Definition of a node in the binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform post-order traversal of a binary tree
void postorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    // Traverse left subtree
    postorderTraversal(root->left);

    // Traverse right subtree
    postorderTraversal(root->right);

    // Visit root node
    cout << root->val << " ";
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
