#ifndef TIC_TAK_TOE_TREENODE_H
#define TIC_TAK_TOE_TREENODE_H

#include <vector>
#include "PlayField.h"

class TreeNode{
public:
    explicit TreeNode(PlayField newState, TreeNode* parent);
    bool isTerminal() const;
    void addChild(TreeNode* child);
    TreeNode& operator[](int index);
    int childCount() const;
    const PlayField& value() const;
private:
    int childQty() const;
    const PlayField state;
    std::vector<TreeNode*> children;
    const TreeNode* parent = nullptr;
};

#endif