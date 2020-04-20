#ifndef BINARYTREE_TREENODE_H
#define BINARYTREE_TREENODE_H


class TreeNode {
public:    
    TreeNode() = default;
    TreeNode(const int value): m_value(value) {}
    void SetValue(int value) { m_value = value; }
    void SetLeftNode(TreeNode* iNode) { m_left = iNode; };
    void SetRightNode(TreeNode* iNode) { m_right = iNode; };
    int GetValue() const { return m_value; };
    TreeNode* GetLeftNode() const { return m_left; };
    TreeNode* GetRightNode() const  { return m_right; };
    ~TreeNode();
private:
    TreeNode* m_left = nullptr;
    TreeNode* m_right = nullptr;
    int m_value = 0;
};


#endif
