#ifndef TIC_TAK_TOE_PLAYFIELD_H
#define TIC_TAK_TOE_PLAYFIELD_H
#include <vector>
#include <cassert>


class PlayField {
public:
    enum FieldStatus {fsInvalid, fsCrossesWin, fsNoughtsWin, fsDraw, fsNormal};
    enum CellState {csEmpty, csCross, csNought};
    class CellIdx {
    public:
        static CellIdx CreateIndex(int x, int y){
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
        CellIdx(int x, int y){
            this->x = x;
            this->y = y;
        }
        int x;
        int y;
    };
    CellState operator[](CellIdx index) const;
    std::vector<CellIdx> getEmptyCells() const;
    FieldStatus checkFieldStatus() const;
    PlayField makeMove(CellIdx* index) const;
    static int GetArrayIndexFromCellIdx(CellIdx* index){
        return index->GetX() * 3 + index->GetY();
    }
    static PlayField::CellIdx GetCellIdxFromArrayIndex(int index){
        return PlayField::CellIdx::CreateIndex(index / 3, index % 3);
    }
private:
    CellState state[9]{csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty};
    PlayField* operator+(CellIdx* index);
    bool isVerticalLine(PlayField::CellState mark, int dif) const;
    bool isHorizontalLine(PlayField::CellState mark, int dif) const;
    bool isDiagonalLine(PlayField::CellState mark) const;
    bool HasWinSequence(PlayField::CellState mark) const;
    CellState GetNextMove() const;
};


#endif
