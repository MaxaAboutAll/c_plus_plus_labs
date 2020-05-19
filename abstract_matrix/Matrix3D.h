#ifndef ABSTRACT_MATRIX_MATRIX3D_H
#define ABSTRACT_MATRIX_MATRIX3D_H
#include "MatrixBase.h"

class Matrix3D: public MatrixBase {
public:
    Matrix3D();
    int element(unsigned int i, unsigned int j) const override;
    int &element(unsigned int i, unsigned int j) override;

private:
    static constexpr int dimension = 3;
    int state[dimension][dimension];
};


#endif
