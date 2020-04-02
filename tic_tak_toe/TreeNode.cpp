#include "TreeNode.h"

TreeNode::TreeNode(PlayField newState, TreeNode* parent): state(newState), parent(parent) {}

TreeNode& TreeNode::operator[](const int index) const {
    return *children[index];
}

const PlayField& TreeNode::value() const {
    return state;
}

bool TreeNode::isTerminal() const {
    assert(state.checkFieldStatus() != PlayField::fsInvalid);
    return state.checkFieldStatus()== PlayField::fsNoughtsWin || 
    state.checkFieldStatus() == PlayField::fsCrossesWin || 
    state.checkFieldStatus() == PlayField::fsDraw;
}

void TreeNode::addChild(TreeNode* child) {
    assert(children.size() <= 9);
    child->parent = this;
    children.push_back(child);
}

int TreeNode::childCount() const {
    return children.size();
}

int TreeNode::childQty() const {
    return (parent ? parent->childQty() - 1 : 9);
}
