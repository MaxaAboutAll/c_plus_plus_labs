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

        int X() const{
            return x;
        }

        int Y() const{
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
    PlayField makeMove(CellIdx index) const;
private:
    CellState state[3][3]{csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty};
    PlayField operator+(CellIdx index) const;
    bool isVerticalLine(PlayField::CellState mark, int dif) const;
    bool isHorizontalLine(PlayField::CellState mark, int dif) const;
    bool isDiagonalLine(PlayField::CellState mark) const;
    bool HasWinSequence(PlayField::CellState mark) const;
    CellState GetNextMove() const;
    void CrossesAndNoughtsCount(int &crossesCount, int &noughtsCount) const;
};


#endif
