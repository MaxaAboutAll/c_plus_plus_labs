#include "PlayField.h"

using namespace std;

bool PlayField::isVerticalLine(const PlayField::CellState mark, const int dif) const {
    for (int y = 0; y < 3; y++)
        if (state[dif][y] != mark)
            return false;
    return true;
}

bool PlayField::isHorizontalLine(const PlayField::CellState mark, const int dif) const {
    for (auto x : state)
       if (x[dif] != mark)
            return false;
    return true;
}

bool PlayField::isDiagonalLine(const PlayField::CellState mark) const {
    return (state[0][0] == mark && state[1][1] == mark && state[2][2] == mark)
           || (state[2][0] == mark && state[1][1] == mark && state[0][2] == mark);
}

bool PlayField::HasWinSequence(const PlayField::CellState mark) const {
    bool horiz = isHorizontalLine(mark, 0) || isHorizontalLine(mark, 1) || isHorizontalLine(mark, 2);
    bool vert = isVerticalLine(mark, 0) || isVerticalLine(mark, 1) || isVerticalLine( mark, 2);
    bool diagonal = isDiagonalLine(mark);
    return horiz || vert || diagonal;
}

PlayField PlayField::operator+(const PlayField::CellIdx index) const {
    assert(state[index.X()][index.Y()] == csEmpty);
    PlayField newField = PlayField(*this);
    newField.state[index.X()][index.Y()] = GetNextMove();
    return newField;
}

PlayField::CellState PlayField::operator[](const CellIdx index) const {
    return state[index.X()][index.Y()];
}

vector<PlayField::CellIdx> PlayField::getEmptyCells() const {
    vector<CellIdx> emptyCells;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (state[x][y] == csEmpty)
                emptyCells.push_back(PlayField::CellIdx::CreateIndex(x, y));
    return emptyCells;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
    int crossesCount = 0;
    int noughtsCount = 0;
    CrossesAndNoughtsCount(crossesCount, noughtsCount);
    bool isCrossesWin = HasWinSequence(csCross);
    bool isNoughtsWin = HasWinSequence(csNought);
    bool isNormal = abs(crossesCount - noughtsCount) < 2;
    bool isMovesEnd = getEmptyCells().empty();
    FieldStatus isWinOrDraw = isCrossesWin ? fsCrossesWin : (isNoughtsWin ? fsNoughtsWin : fsDraw);
    if(isCrossesWin || isNoughtsWin || (isNormal && isMovesEnd))
        return isWinOrDraw;
    return isNormal ? fsNormal : fsInvalid;
}

PlayField PlayField::makeMove(const PlayField::CellIdx index) const {
    assert(state[index.X()][index.Y()] == csEmpty);
    return PlayField(*this) + index;
}

PlayField::CellState PlayField::GetNextMove() const {
    int crossCount = 0 , noughtCount = 0;
    CrossesAndNoughtsCount(crossCount, noughtCount);
    return crossCount > noughtCount ? csNought: csCross;
}

void PlayField::CrossesAndNoughtsCount(int &crossesCount, int &noughtsCount) const {
    for (auto x : state)
        for (int y = 0; y < 3; y++)
            switch (x[y]){
                case csNought:
                    noughtsCount++;
                    break;
                case csCross:
                    crossesCount++;
                    break;
            }
}
