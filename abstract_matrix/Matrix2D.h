#ifndef ABSTRACT_MATRIX_MATRIX2D_H
#define ABSTRACT_MATRIX_MATRIX2D_H

#include "MatrixBase.h"
    class Matrix2D: public MatrixBase {
    public:
    Matrix2D(): MatrixBase(2){
        for (int x = 0; x < 2; ++x) 
        for (int y = 0; y < 2; ++y) 
            state[x][y] = x * 3 + y + 1;
    };
    int element(unsigned int i, unsigned int j) const override;
    int &element(unsigned int i, unsigned int j) override;
    private:
    int state[2][2];   
};


#endif
