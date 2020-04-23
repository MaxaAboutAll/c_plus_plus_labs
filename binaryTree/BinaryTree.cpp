#include "BinaryTree.h"

TreeNode* BinaryTree::Insert(TreeNode* root, const int value) {
    if (root == nullptr){
        root = new TreeNode(value);
    } else 
    if (root->GetValue() > value)
        root->SetLeftNode(Insert(root->GetLeftNode(), value));
    else 
        root->SetRightNode(Insert(root->GetRightNode(), value));
    return root;
}

TreeNode *BinaryTree::Search(TreeNode *const root, const int value) {
    if (root == nullptr)
        return nullptr;
    if (root->GetValue() == value)
        return root;
    if (value < root->GetValue())
        return Search(root->GetLeftNode(), value);
    else
        return Search(root->GetRightNode(), value);
}
