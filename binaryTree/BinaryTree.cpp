#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    m_root = nullptr;
}

BinaryTree::BinaryTree(TreeNode *iRoot) {
    m_root = iRoot;
}

BinaryTree::~BinaryTree() {
    delete m_root;
}

void BinaryTree::Insert(int value) {
    if (m_root == nullptr)
        m_root = new TreeNode(value);
    else
        Insert(m_root, value);
}

TreeNode* BinaryTree::Search(const int value) const {
    return Search(m_root, value);
}

TreeNode* BinaryTree::Insert(TreeNode *root, int value) {
    if (root == nullptr){
        root = new TreeNode(value);
    } else if (root->GetValue() > value){
        root->SetLeftNode(Insert(root->GetLeftNode(), value));
    } else {
        root->SetRightNode(Insert(root->GetRightNode(), value));
    }
    return root;
}

TreeNode *BinaryTree::Search(TreeNode *root, const int value) const {
    if (root == nullptr)
        return nullptr;
    if (root->GetValue() == value)
        return root;
    if (root->GetValue() > value) 
        return Search(root->GetLeftNode(), value);
    else
        return Search(root->GetRightNode(), value);
}
