#include "Matrix3D.h"

int Matrix3D::element(unsigned int i, unsigned int j) const {
    return state[i][j];
}

int &Matrix3D::element(unsigned int i, unsigned int j) {
    return state[i][j];
}
