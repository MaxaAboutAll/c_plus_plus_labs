#include "TreeNode.h"

TreeNode::TreeNode() {
    m_left = nullptr;
    m_right = nullptr;
    m_value = 0;
}

TreeNode::TreeNode(int value) {
    m_value = value;
    m_left = nullptr;
    m_right = nullptr;
}

TreeNode::~TreeNode() {
    delete m_right;
    delete m_left;
}

TreeNode* TreeNode::GetRightNode() {
    return m_right;
}

TreeNode* TreeNode::GetLeftNode() {
    return m_left;
}

void TreeNode::SetValue(int value) {
    m_value = value;
}

void TreeNode::SetLeftNode(TreeNode* iNode) {
    m_left = iNode;
}

void TreeNode::SetRightNode(TreeNode* iNode) {
    m_right = iNode;
}

int TreeNode::GetValue() const {
    return m_value;
}
