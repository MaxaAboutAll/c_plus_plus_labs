#ifndef TIC_TAK_TOE_XOPLAYER_H
#define TIC_TAK_TOE_XOPLAYER_H
#include "TreeNode.h"
#include "PlayField.h"

class XOPlayer {
public:
    XOPlayer(TreeNode& iStepsTree, PlayField::FieldStatus myMark){
        stepsTree = &iStepsTree;
        currentPlayerWinSequence = myMark;
    }
    PlayField::FieldStatus fieldStatus() const { return currentFieldState.checkFieldStatus(); };
    PlayField currentState() const { return currentFieldState; };
    void MakeMove();
    void MakeMove(PlayField::CellIdx index);
private:
    TreeNode* stepsTree;
    PlayField currentFieldState;
    PlayField::FieldStatus currentPlayerWinSequence;
    void checkFieldState();
    PlayField::CellIdx GetNextMoveIndex(PlayField bestSate); 
};


#endif
