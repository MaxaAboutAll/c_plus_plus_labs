#include "TreeNode.h"

TreeNode::TreeNode(PlayField newState, TreeNode* parent = nullptr): state(newState), parent(parent){}

TreeNode& TreeNode::operator[](int index) {
    return *children[index];
}

const PlayField& TreeNode::value() const {
    return state;
}

bool TreeNode::isTerminal() const {
    return childQty() == 0;
}

void TreeNode::addChild(TreeNode* child) {
    child->parent = this;
    children.push_back(child);
}

int TreeNode::childCount() const{
    return children.size();
}

int TreeNode::childQty() const {
    return value().checkFieldStatus() == PlayField::fsNormal? (int) state.getEmptyCells().size() - childCount(): 0;
}
