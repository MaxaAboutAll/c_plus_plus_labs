#include "PlayField.h"

using namespace std;

bool PlayField::isVerticalLine(PlayField::CellState mark, int dif) const {
    bool line = true;
    for (int i = 0; i < 9; i++)
        if(i%3 == dif && state[i] != mark)
            line = false;
    return line;
}

bool PlayField::isHorizontalLine(PlayField::CellState mark, int dif) const {
    bool line = true;
    for (int i = 0; i < 9; i++)
        if(i/3 == dif && state[i] != mark)
            line = false;
    return line;
}

bool PlayField::isDiagonalLine(PlayField::CellState mark) const {
    return (state[0] == mark && state[4] == mark && state[8] == mark)
           || (state[2] == mark && state[4] == mark && state[6] == mark);
}

bool PlayField::HasWinSequence(PlayField::CellState mark) const {
    bool horiz = isHorizontalLine(mark, 0) || isHorizontalLine(mark, 1) || isHorizontalLine(mark, 2);
    bool vert = isVerticalLine(mark, 0) || isVerticalLine(mark, 1) || isVerticalLine( mark, 2);
    bool diagonal = isDiagonalLine(mark);
    return horiz || vert || diagonal;
}

PlayField* PlayField::operator+(PlayField::CellIdx* index) {
    assert(state[GetArrayIndexFromCellIdx(index)] == csEmpty);
    auto newField = new PlayField(*this);
    newField->makeMove(index);
    return newField;
}

PlayField::CellState PlayField::operator[](CellIdx index) const {
    return state[GetArrayIndexFromCellIdx(&index)];
}

vector<PlayField::CellIdx> PlayField::getEmptyCells() const{
    vector<CellIdx> emptyCells;
    for (int i = 0; i < 9; i++) 
        if (state[i] == csEmpty)
            emptyCells.push_back(PlayField::GetCellIdxFromArrayIndex(i));
    return emptyCells;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
    int crossesCount = 0;
    int noughtsCount = 0;
    bool isCrossesWin = HasWinSequence(csCross);
    bool isNoughtsWin = HasWinSequence(csNought);
    bool isNormal = abs(crossesCount - noughtsCount) < 2;
    bool isMovesEnd = getEmptyCells().empty();
    FieldStatus isWinOrDraw = isCrossesWin ? fsCrossesWin : (isNoughtsWin ? fsNoughtsWin : fsDraw);
    if(isCrossesWin || isNoughtsWin || (isNormal && isMovesEnd))
        return isWinOrDraw;
    return isNormal ? fsNormal : fsInvalid;
}

PlayField PlayField::makeMove(PlayField::CellIdx* index) const{
    assert(state[GetArrayIndexFromCellIdx(index)] == csEmpty);
    PlayField newField = PlayField(*this);
    newField.state[GetArrayIndexFromCellIdx(index)] = GetNextMove();
    return newField;
}

PlayField::CellState PlayField::GetNextMove() const{
    int crossCount = 0 , noughtCount = 0;
    for (auto & i : state) {
        if (i == csCross){
            crossCount++;
            continue;            
        }
        if (i == csNought){
            noughtCount++;
            continue;
        }
    }
    return crossCount > noughtCount? csNought: csCross;
}
