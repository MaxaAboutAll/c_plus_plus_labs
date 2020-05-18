#ifndef ABSTRACT_MATRIX_MATRIX3D_H
#define ABSTRACT_MATRIX_MATRIX3D_H
#include "MatrixBase.h"

class Matrix3D: public MatrixBase {
public:
    Matrix3D(): MatrixBase(3) {
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
                state[x][y] = x * 3 + y + 1;
    };
    int element(unsigned int i, unsigned int j) const override;
    int &element(unsigned int i, unsigned int j) override;

private:
    int state[3][3];
};


#endif
