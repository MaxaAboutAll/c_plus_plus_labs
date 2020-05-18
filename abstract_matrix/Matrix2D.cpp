#include "Matrix2D.h"

int Matrix2D::element(unsigned int i, unsigned int j) const {
    return state[i][j];
}

int &Matrix2D::element(unsigned int i, unsigned int j) {
    return state[i][j];
}
