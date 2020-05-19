#ifndef ABSTRACT_MATRIX_MATRIX2D_H
#define ABSTRACT_MATRIX_MATRIX2D_H

#include "MatrixBase.h"
    class Matrix2D: public MatrixBase {
    public:
    Matrix2D();
    int element(unsigned int i, unsigned int j) const override;
    int &element(unsigned int i, unsigned int j) override;
    private:
    static constexpr int dimension = 2;
    int state[dimension][dimension];   
};


#endif
