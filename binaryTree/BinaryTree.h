#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#include "TreeNode.h"

class BinaryTree {
public:
    BinaryTree();
    BinaryTree(TreeNode* iRoot);
    ~BinaryTree();
    void Insert(int value);
    TreeNode* Search(const int value) const;
private:
    TreeNode* m_root;
    TreeNode* Insert(TreeNode* root, int value);
    TreeNode* Search(TreeNode* root, const int value) const;
};


#endif
