#include "PlayField.h"

bool isVerticalLine(PlayField::CellIdx* field, PlayField::CellState mark, int dif){
    bool line = true;
    for (int i = 0; i < 9; i++)
        if(i%3 == dif && field[i].GetState() != mark)
            line = false;
    return line;
}

bool isHorizontalLine(PlayField::CellIdx* field, PlayField::CellState mark, int dif){
    bool line = true;
    for (int i = 0; i < 9; i++)
        if(i/3 == dif && field[i].GetState() != mark)
            line = false;
    return line;
}

bool isDiagonalLine(PlayField::CellIdx* field, PlayField::CellState mark){
    return (field[0].GetState() == mark && field[4].GetState() == mark && field[8].GetState() == mark)
           || (field[2].GetState() == mark && field[4].GetState() == mark && field[6].GetState() == mark);
}

bool HasWinSequence(PlayField::CellIdx* field, PlayField::CellState mark)
{
    bool horiz = isHorizontalLine(field, mark, 0) || isHorizontalLine(field, mark, 1) || isHorizontalLine(field, mark, 2);
    bool vert = isVerticalLine(field, mark, 0) || isVerticalLine(field, mark, 1) || isVerticalLine(field, mark, 2);
    bool diagonal = isDiagonalLine(field, mark);
    return horiz || vert || diagonal;
}

PlayField PlayField::operator+(PlayField::CellIdx index) {
    assert(state[index.GetX() + index.GetY() * 3].GetState() == csEmpty);
    state[index.GetX() + index.GetY() * 3] = index;
    return *this;
}

PlayField::CellState PlayField::operator[](CellIdx index) {
    return state[index.GetX() + index.GetY() * 3].GetState();
}

vector<PlayField::CellIdx> PlayField::getEmptyCells() {
    vector<CellIdx> emptyCells;
    for (auto i : state)
        if(i.GetState() == csEmpty)
            emptyCells.push_back(i);
    return emptyCells;
}

PlayField::FieldStatus PlayField::checkFieldStatus() {
    int crossesCount = 0;
    int noughtsCount = 0;
    bool isCrossesWin = HasWinSequence(state, csCross);
    bool isNoughtsWin = HasWinSequence(state, csNought);
    bool isNormal = abs(crossesCount - noughtsCount) < 2;
    bool isMovesEnd = getEmptyCells().empty();
    FieldStatus isWinOrDraw = isCrossesWin ? fsCrossesWin : isNoughtsWin? fsNoughtsWin : fsDraw;
    if(isCrossesWin || isNoughtsWin || (isNormal && isMovesEnd))
        return isWinOrDraw;
    return isNormal ? fsNormal : fsInvalid;
}

PlayField PlayField::makeMove(PlayField::CellIdx index) const{
    assert(state[index.GetX() + index.GetY() * 3].GetState() == csEmpty);
    assert(index.GetState() != csEmpty);
    assert(lastMove.GetState() != index.GetState());
    PlayField newField = PlayField(*this);
    newField.state[index.GetX() + index.GetY() * 3] = index;
    newField.lastMove = index;
    return newField;
}
