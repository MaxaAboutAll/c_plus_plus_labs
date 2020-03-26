#ifndef TIC_TAK_TOE_TREENODE_H
#define TIC_TAK_TOE_TREENODE_H

#include <vector>
#include "PlayField.h"

using namespace std;
class TreeNode{
public:
    explicit TreeNode(PlayField newState);
    bool isTerminal();
    void addChild(TreeNode child);
    TreeNode operator[](int index);
    int childCount();
    PlayField value();
    TreeNode* GetParent();
private:
    int childQty();
    PlayField state;
    vector<TreeNode> children;
    TreeNode* parent = nullptr;
};

#endif