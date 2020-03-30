#include <iostream>
#include <vector>
#include "PlayField.h"
#include "TreeNode.h"
#include <string>

using namespace std;

/*
 * Третьяков Максим
 * Студент группы РИ-280017
 * */


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
            PrintCell(field[PlayField::CellIdx::CreateIndex(j, i)]);
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

void FillTree(TreeNode& root, int (&results)[3]){
    if(root.isTerminal()){
        switch (root.value().checkFieldStatus()){
            case PlayField::fsDraw:
                results[0]++;
                break;
            case PlayField::fsCrossesWin:
                results[1]++;
                break;
            case PlayField::fsNoughtsWin:
                results[2]++;
                break;
        }
        return;
    }
    auto emptyCells = root.value().getEmptyCells();
    for (int i = 0; i < emptyCells.size(); i++) {
        root.addChild(new TreeNode(root.value().makeMove(&emptyCells[i]), nullptr));
        FillTree(root[i], results);
    }
}
int main() {
    PlayField startField;
    TreeNode root = TreeNode(startField, nullptr);
    TreeNode rootForView = TreeNode(startField, nullptr);
    auto empties = startField.getEmptyCells();
    for (int i = 0; i < empties.size(); i++) {
        root.addChild(new TreeNode(root.value().makeMove(&empties[i]), nullptr));
        rootForView.addChild(new TreeNode(root.value().makeMove(&empties[i]), nullptr));
    }
    PrintSeparator();
    for (int i = 0; i < 9; i++) {
        int results[3] = {0,0,0};
        FillTree(root[i], results);
        PrintTree(rootForView[i]);
        cout<< "Crosses win "<< results[1]<<endl;
        cout<< "Noughts win "<< results[2]<<endl;
        cout<< "Draws "<< results[0]<<endl;
        PrintSeparator();
    }
    int a;
    cin>> a;
    return 0;
}
