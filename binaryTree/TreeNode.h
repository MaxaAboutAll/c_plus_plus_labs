#ifndef BINARYTREE_TREENODE_H
#define BINARYTREE_TREENODE_H


class TreeNode {
public:
    TreeNode();
    TreeNode(int value);
    void SetValue(int value);
    void SetLeftNode(TreeNode* iNode);
    void SetRightNode(TreeNode* iNode);
    int GetValue() const;
    TreeNode* GetLeftNode();
    TreeNode* GetRightNode();
    ~TreeNode();
private:
    TreeNode* m_left;
    TreeNode* m_right;
    int m_value;
};


#endif
