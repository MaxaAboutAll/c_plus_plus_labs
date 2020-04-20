#include "TreeNode.h"

TreeNode::~TreeNode() {
    delete m_right;
    delete m_left;
}
