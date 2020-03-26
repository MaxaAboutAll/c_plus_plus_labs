#ifndef TIC_TAK_TOE_PLAYFIELD_H
#define TIC_TAK_TOE_PLAYFIELD_H
#include <iostream>
#include <vector>
#include <cassert>


class PlayField {
public:
    enum FieldStatus {fsInvalid, fsCrossesWin, fsNoughtsWin, fsDraw, fsNormal};
    enum CellState {csEmpty, csCross, csNought};
    class CellIdx{
    public:
        static CellIdx CreateCell(int x, int y){
            assert(x >= 0 && y >= 0 && x <=2 && y <= 2 );
            return {x, y};
        }

        int GetX(){
            return x;
        }

        int GetY(){
            return y;
        }
    private:
        int x;
        int y;
        CellIdx(int x, int y){
            this->x = x;
            this->y = y;
        }
    };
    CellState operator[](CellIdx index);
    std::vector<CellIdx*> getEmptyCells() const;
    FieldStatus checkFieldStatus() const;
    PlayField makeMove(CellIdx index) const;
private:
    PlayField operator+(CellIdx index);
    CellState state[9]{csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty};
    int GetArrayIndexFromCellIdx(CellIdx* index) const;
    PlayField::CellIdx GetCellIdxFromArrayIndex(int index) const;
    bool isVerticalLine(const PlayField::CellState* field, PlayField::CellState mark, int dif) const;
    bool isHorizontalLine(const PlayField::CellState* field, PlayField::CellState mark, int dif) const;
    bool isDiagonalLine(const PlayField::CellState* field, PlayField::CellState mark) const;
    bool HasWinSequence(const PlayField::CellState* field, PlayField::CellState mark) const;
    CellState GetLastMove() const;
};


#endif
