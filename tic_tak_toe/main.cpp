#include <iostream>
#include <vector>
#include "PlayField.h"
#include "TreeNode.h"
#include "XOPlayer.h"
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
    PrintSeparator();
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            PrintCell(field[PlayField::CellIdx::CreateIndex(x, y)]);
        }
        cout <<"|" << endl;
    }
    PrintSeparator();
}

void FillTree(TreeNode& root){
    if(root.isTerminal()){
        return;
    }
    auto emptyCells = root.value().getEmptyCells();
    for (int i = 0; i < emptyCells.size(); i++) {
        root.addChild(new TreeNode(root.value().makeMove(emptyCells[i]), nullptr));
        FillTree(root[i]);
    }
}

void CountResults(TreeNode& root, int (&results)[3]){
    if(root.isTerminal()){
        switch (root.value().checkFieldStatus()){
            case PlayField::fsCrossesWin:
                results[0]++;
                break;
            case PlayField::fsNoughtsWin:
                results[1]++;
                break;
            case PlayField::fsDraw:
                results[2]++;
                break;
        }
        return;
    } 
    auto emptyCells = root.value().getEmptyCells();
    for (int i = 0; i < root.childCount(); i++) {
        CountResults(root[i], results);
    }
}

int main() {
    PlayField startField;
    TreeNode root = TreeNode(startField, nullptr);
    FillTree(root);
    cout<<"Хотите поиграть введите 1, хотите увидеть количество побед/поражний/ничиьх введите 0"<<endl; 
    int a;
    cin >> a;
    if(a == 0) {
        for (int i = 0; i < 9; i++) {
            PrintField(root[i].value());
            int results[3] = {0, 0, 0};
            CountResults(root[i], results);
            cout << "Crosses win " << results[0] << endl;
            cout << "Noughts win " << results[1] << endl;
            cout << "Draws " << results[2] << endl;
            PrintSeparator();
        }
    }
    if( a== 1) {
        cout << "Select player (0 - Xs, 1 - Os)" << std::endl;
        int sel_player;
        cin >> sel_player;
        XOPlayer player(root, (sel_player == 0 ? PlayField::fsNoughtsWin : PlayField::fsCrossesWin));
        do {
            PrintField(player.currentState());
            if (sel_player == 0) {
                cout << "Vvedi index x,y 0..2" << endl;
                int x, y;
                cin >> x >> y;
                player.MakeMove(PlayField::CellIdx::CreateIndex(x, y));
                PrintField(player.currentState());
                player.MakeMove();
            } else {
                player.MakeMove();
                PrintField(player.currentState());
                cout << "Vvedi index x,y 0..2" << endl;
                int x, y;
                cin >> x >> y;
                player.MakeMove(PlayField::CellIdx::CreateIndex(x, y));
            }
        } while (player.fieldStatus() == PlayField::fsNormal);
        PrintField(player.currentState());
        if (player.fieldStatus() == PlayField::fsCrossesWin)
            cout << "Crosses are win" << endl;
        if (player.fieldStatus() == PlayField::fsNoughtsWin)
            cout << "Noughts are win" << endl;
    }
    cin >> a;
    return 0;
}
