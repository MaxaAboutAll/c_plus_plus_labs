#include "BinaryTree.h"

TreeNode* BinaryTree::Insert(TreeNode *const root, const int value) {
    if (root == nullptr){
        m_root = new TreeNode(value);
    } else if (root->GetValue() > value){
        if (root->GetLeftNode())
            Insert(root->GetLeftNode(), value);
        else
            root->SetLeftNode(new TreeNode(value));
    } else {
        if (root->GetRightNode())
            Insert(root->GetRightNode(), value);
        else
            root->SetRightNode(new TreeNode(value));
    }
    return root;
}

TreeNode *BinaryTree::Search(TreeNode *const root, const int value) const {
    if (root == nullptr)
        return nullptr;
    if (root->GetValue() == value)
        return root;
    if (root->GetValue() > value)
        return Search(root->GetLeftNode(), value);
    else
        return Search(root->GetRightNode(), value);
}
