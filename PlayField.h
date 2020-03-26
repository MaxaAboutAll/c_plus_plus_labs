#ifndef TIC_TAK_TOE_PLAYFIELD_H
#define TIC_TAK_TOE_PLAYFIELD_H
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class PlayField {
public:
    enum FieldStatus {fsInvalid, fsCrossesWin, fsNoughtsWin, fsDraw, fsNormal};
    enum CellState {csEmpty, csCross, csNought};
    class CellIdx{
    private:
        int x;
        int y;
        CellState state;
        CellIdx(int x, int y, CellState state){
            this->x = x;
            this->y = y;
            this->state = state;
        }
    public:
        CellIdx(){
            this->x = 0;
            this->y = 0;
            this->state = csEmpty;
        }
        static CellIdx CreateCell(int x, int y, CellState state){
            assert(x >= 0 && y >= 0 && x <=2 && y <= 2 );
            return {x, y, state};
        }

        static CellIdx CreateIndexCell(int x, int y){
            assert(x >= 0 && y >= 0 && x <=2 && y <= 2 );
            return {x, y, csEmpty};
        }

        int GetX(){
            return x;
        }

        int GetY(){
            return y;
        }

        CellState GetState() const {
            return state;
        }
    };
    CellState operator[](CellIdx index);
    vector<CellIdx> getEmptyCells();
    FieldStatus checkFieldStatus();
    PlayField makeMove(CellIdx index) const;
private:
    PlayField operator+(CellIdx index);
    CellIdx lastMove;
    CellIdx state[9];
};


#endif
