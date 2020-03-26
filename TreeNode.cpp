#include "TreeNode.h"
#include "PlayField.h"

TreeNode::TreeNode(PlayField newState) {
    state = newState;
}

TreeNode TreeNode::operator[](int index) {
    return children[index];
}

PlayField TreeNode::value() {
    return TreeNode::state;
}

bool TreeNode::isTerminal() {
    return state.checkFieldStatus() != PlayField::fsNormal;
}

void TreeNode::addChild(TreeNode child) {
    child.parent = this;
    children.push_back(child);
}

int TreeNode::childCount() {
    return children.size();
}

TreeNode* TreeNode::GetParent() {
    return parent;
}
