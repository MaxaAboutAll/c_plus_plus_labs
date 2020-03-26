#include "PlayField.h"

using namespace std;

bool PlayField::isVerticalLine(const PlayField::CellState* field, PlayField::CellState mark, int dif) const{
    bool line = true;
    for (int i = 0; i < 9; i++)
        if(i%3 == dif && field[i] != mark)
            line = false;
    return line;
}

bool PlayField::isHorizontalLine(const PlayField::CellState* field, PlayField::CellState mark, int dif) const{
    bool line = true;
    for (int i = 0; i < 9; i++)
        if(i/3 == dif && field[i] != mark)
            line = false;
    return line;
}

bool PlayField::isDiagonalLine(const PlayField::CellState* field, PlayField::CellState mark) const{
    return (field[0] == mark && field[4] == mark && field[8] == mark)
           || (field[2] == mark && field[4] == mark && field[6] == mark);
}

bool PlayField::HasWinSequence(const PlayField::CellState* field, PlayField::CellState mark) const {
    bool horiz = isHorizontalLine(field, mark, 0) || isHorizontalLine(field, mark, 1) || isHorizontalLine(field, mark, 2);
    bool vert = isVerticalLine(field, mark, 0) || isVerticalLine(field, mark, 1) || isVerticalLine(field, mark, 2);
    bool diagonal = isDiagonalLine(field, mark);
    return horiz || vert || diagonal;
}

int PlayField::GetArrayIndexFromCellIdx(CellIdx* index) const {
    return index->GetX() + index->GetY() * 3;
}

PlayField::CellIdx PlayField::GetCellIdxFromArrayIndex(int index) const {
    return PlayField::CellIdx::CreateCell(index/3, index%3);
}

PlayField PlayField::operator+(PlayField::CellIdx index) {
    assert(state[GetArrayIndexFromCellIdx(&index)] == csEmpty);
    state[GetArrayIndexFromCellIdx(&index)] = GetLastMove() == csCross ? csNought : csCross;;
    return *this;
}

PlayField::CellState PlayField::operator[](CellIdx index) {
    return state[GetArrayIndexFromCellIdx(&index)];
}

vector<PlayField::CellIdx*> PlayField::getEmptyCells() const{
    vector<CellIdx*> emptyCells;
    for (int i = 0; i < 9; ++i) {
        if (state[i] == csEmpty){
            auto cell = GetCellIdxFromArrayIndex(i);
            emptyCells.push_back(&cell);
        }
    }
    return emptyCells;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
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
    assert(state[GetArrayIndexFromCellIdx(&index)] == csEmpty);
    PlayField newField = PlayField(*this);
    newField.state[GetArrayIndexFromCellIdx(&index)] = GetLastMove() == csCross ? csNought : csCross;
    return newField;
}

PlayField::CellState PlayField::GetLastMove() const{
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
    return crossCount > noughtCount? csCross: csNought;
}
