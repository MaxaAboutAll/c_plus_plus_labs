#include <iostream>
#include <vector>
#include "PlayField.h"
#include "TreeNode.h"
#include <string>

using namespace std;

void PrintSeparator(){
    static const string separator = "-------";
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
            PrintCell(field[PlayField::CellIdx::CreateCell(j, i)]);
        }
        cout <<"|" << endl;
    }
    PrintSeparator();
}

void PrintTree(TreeNode root){
    PrintField(root.value());
    for (int i = 0; i < root.childCount(); i++){
        PrintTree(root[i]);
    }
}

void FillTree(TreeNode*& root, PlayField::CellState mark, int index){
    while(!root->isTerminal()) {
        for (int i = 0; i < 9; ++i) {
            auto startField = root->value();
            if (startField[PlayField::CellIdx::CreateCell(i%3, i/3)] == PlayField::csEmpty) {
                auto newField = startField.makeMove(PlayField::CellIdx::CreateCell(i % 3, i / 3));
                auto newRoot = new TreeNode(newField, root);
                root->addChild(newRoot);
            }
        }
//        PrintTree(root);
        root = &root->operator[](index);
        mark = mark == PlayField::csCross?PlayField::csNought:PlayField::csCross;
    }
}

int main() {
    PlayField startField;
    TreeNode root = TreeNode(startField, nullptr);
    PrintSeparator();
    TreeNode* temp = &root;
    FillTree(temp, PlayField::csCross, 0);
    temp = &root;
    FillTree(temp, PlayField::csCross, 1);
    temp = &root;
    FillTree(temp, PlayField::csCross, 2);
//    temp = &root;
//    FillTree(temp, PlayField::csCross, 3);
//    temp = &root;
//    FillTree(temp, PlayField::csCross, 4);
//    temp = &root;
//    FillTree(temp, PlayField::csCross, 5);
//    temp = &root;
//    FillTree(temp, PlayField::csCross, 6);
//    temp = &root;
//    FillTree(temp, PlayField::csCross, 7);
//    temp = &root;
//    FillTree(temp, PlayField::csCross, 8);
    PrintTree(root);
    return 0;
}
