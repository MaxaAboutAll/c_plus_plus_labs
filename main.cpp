#include <iostream>
#include <vector>
#include "PlayField.h"
#include "TreeNode.h"
#include <string>

using namespace std;

void PrintSeparator(){
    string separator = "-------";
    cout << separator<< endl;
}

void PrintCell(PlayField::CellState cell){
    string writing = "| ";
    switch (cell){
        case PlayField::csCross:
            writing = "|X";
            break;
        case PlayField::csNought:
            writing = "|O";
            break;
    }
    cout << writing;
}

void PrintField(PlayField field){
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            PrintCell(field[PlayField::CellIdx::CreateIndexCell(j, i)]);
        }
        cout <<"|" << endl;
    }
    PrintSeparator();
}

void PrintTree(TreeNode root){
    PrintField(root.value());
//    for (int i = 0; i < root.childCount(); i++)
//        PrintTree(root[i]);
    while(root.GetParent() != nullptr) {
        root = *root.GetParent();
        PrintTree(root);
    }
}

void FillTree(TreeNode& root, PlayField::CellState mark){
    while(!root.isTerminal()) {
        for (int i = 0; i < 9; ++i) {
            auto startField = root.value();
            if (startField[PlayField::CellIdx::CreateIndexCell(i%3, i/3)] == PlayField::csEmpty) {
                auto newField = startField.makeMove(PlayField::CellIdx::CreateCell(i % 3, i / 3, mark));
                auto newRoot = TreeNode(newField);
                root.addChild(newRoot);
            }
        }
        root = root[0];
        mark = mark == PlayField::csCross?PlayField::csNought:PlayField::csCross;
    }
}

TreeNode FindRoot(TreeNode root){
    while(root.GetParent() != nullptr)
        root = *root.GetParent();
    return root;
}

int main() {
    PlayField startField;
    TreeNode root = TreeNode(startField);
    PrintSeparator();
    FillTree(root, PlayField::csCross);
//    root = FindRoot(root);
    PrintTree(root);
    return 0;
}
