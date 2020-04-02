#include "TreeNode.h"

TreeNode::TreeNode(PlayField newState, TreeNode* parent): state(newState), parent(parent){}

TreeNode& TreeNode::operator[](const int index) const{
    return *children[index];
}

const PlayField& TreeNode::value() const {
    return state;
}

bool TreeNode::isTerminal() const {
    return state.checkFieldStatus() != PlayField::fsNormal && 
    state.checkFieldStatus() != PlayField::fsInvalid && childQty() == 0;
}

void TreeNode::addChild(TreeNode* child) {
    assert(children.size() < 9);
    child->parent = this;
    children.push_back(child);
}

int TreeNode::childCount() const{
    return children.size();
}

int TreeNode::childQty() const {
    return parent == nullptr ? 9: parent->childQty() - 1;
}
