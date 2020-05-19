#include "Matrix3D.h"

int Matrix3D::element(unsigned int i, unsigned int j) const {
    return state[i][j];
}

int &Matrix3D::element(unsigned int i, unsigned int j) {
    return state[i][j];
}

Matrix3D::Matrix3D():MatrixBase(dimension){
    for (int x = 0; x < dimension; ++x)
        for (int y = 0; y < dimension; ++y)
            state[x][y] = x * 3 + y + 1;
};