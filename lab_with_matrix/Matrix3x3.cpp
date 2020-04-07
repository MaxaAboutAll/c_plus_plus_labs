#include <cassert>
#include <random>
#include <ctime>
#include "Matrix3x3.h"

Matrix3x3::Matrix3x3() {
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            state[i][j] = 0;           
}

int Matrix3x3::element(const int i, const int j) const {
    assert(i >=0 && i < 3 && j >=0 && j < 3);
    return state[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value) {
    assert(i >=0 && i < 3 && j >=0 && j < 3);
    state[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal) {
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            state[i][j] = distribution(generator);
}

int Matrix3x3::sumPrincipalDiag() const {
    int sum = 0;
    for (int i = 0; i < 3; i++) 
        sum += state[i][i];
    return sum;
}

int Matrix3x3::sumSecondaryDiag() const {
    int sum = 0;
    for (int i = 2; i >= 0; i--)
        sum += state[i][2 - i];
    return sum;
}

int Matrix3x3::productPrincipalDiag() const {
    int product = 1;
    for (int i = 0; i < 3; i++)
        product *= state[i][i];
    return product;
}

int Matrix3x3::productSecondaryDiag() const {
    int product = 1;
    for (int i = 2; i >= 0; i--)
        product *= state[i][2 - i];
    return product;
}

int Matrix3x3::sumRow(const int iRow) const {
    assert(iRow >=0 && iRow < 3);
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += state[iRow][i];
    return sum;
}

int Matrix3x3::minColumn(const int iCol) const {
    assert(iCol >=0 && iCol < 3);
    int min = state[0][iCol];
    for (int i = 1; i < 3; i++)
        if (min > state[i][iCol])
            min = state[i][iCol];
    return min;
}

int Matrix3x3::maxColumn(const int iCol) const {
    assert(iCol >=0 && iCol < 3);
    int max = state[0][iCol];
    for (int i = 1; i < 3; i++)
        if (max < state[i][iCol])
            max = state[i][iCol];
    return max;
}
