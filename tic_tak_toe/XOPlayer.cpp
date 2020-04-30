#include "XOPlayer.h"

void CountMyWins(TreeNode& root, int (&results)[3]){
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
        CountMyWins(root[i], results);
    }
}

void XOPlayer::MakeMove(PlayField::CellIdx index) {
    currentFieldState = currentFieldState.makeMove(index);
    checkFieldState();
}

void XOPlayer::MakeMove() {
    if (stepsTree[0].isTerminal())
        return;
    int maxCount = 0, maxIndex = 0, markIndex;
    if (currentPlayerWinSequence == PlayField::fsCrossesWin)
        markIndex = 0;
    else
        markIndex = 1;
    
    for (int i = 0; i < stepsTree->childCount(); ++i) {
        int results[3] = {0,0,0};
        CountMyWins(stepsTree[0][i], results);
            if (results[markIndex] + results[2] > maxCount) {
                maxCount = results[markIndex] + results[2];
                maxIndex = i;
            }
    }
    auto temp = stepsTree[0][maxIndex].value();
    currentFieldState = currentFieldState.makeMove(GetNextMoveIndex(temp));
    checkFieldState();
}

void XOPlayer::checkFieldState() {
    for (int i = 0; i < stepsTree->childCount(); ++i) {
        TreeNode& temp = stepsTree[0][i];
        if ((PlayField) temp.value() == currentFieldState) {
            stepsTree = &stepsTree[0][i];
            break;
        }
    }
}

PlayField::CellIdx XOPlayer::GetNextMoveIndex(PlayField state) {
    PlayField::CellIdx tempIndex = PlayField::CellIdx::CreateIndex(0, 0);
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            tempIndex = PlayField::CellIdx::CreateIndex(x,y);
            if (currentFieldState[tempIndex] != state[tempIndex]) 
                return tempIndex;
        }
    }
    return tempIndex;
}
