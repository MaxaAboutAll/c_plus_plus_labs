#include <random>
#include <cassert>
#include <ctime>
#include "MatrixXnX.h"

MatrixXnX::MatrixXnX(const int iDim) : m_dim(iDim) {
    state = new int[m_dim*m_dim];
    for (int i = 0; i < m_dim; i++)
        for (int j = 0; j < m_dim; j++)
            state[getLinearIndexFromMatrix(i, j)] = 0;
}

int MatrixXnX::element(const int i, const int j) const {
    assert(i >=0 && i < m_dim && j >=0 && j < m_dim);
    return  state[getLinearIndexFromMatrix(i, j)];
}

void MatrixXnX::setElement(const int i, const int j, const int value) {
    assert(i >=0 && i < m_dim && j >=0 && j < m_dim);
    state[getLinearIndexFromMatrix(i, j)] = value;
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal) {
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for (int i = 0; i < m_dim; i++)
        for (int j = 0; j < m_dim; j++)
            state[getLinearIndexFromMatrix(i, j)] = distribution(generator);
}

int MatrixXnX::sumPrincipalDiag() const {
    int sum = 0;
    for (int i = 0; i < m_dim; i++)
        sum += state[getLinearIndexFromMatrix(i, i)];
    return sum;
}

int MatrixXnX::sumSecondaryDiag() const {
    int sum = 0;
    for (int i = m_dim - 1; i >= 0; i--)
        sum += state[getLinearIndexFromMatrix(i, m_dim - 1 -i)];
    return sum;
}

int MatrixXnX::productPrincipalDiag() const {
    int product = 1;
    for (int i = 0; i < m_dim; i++)
        product *= state[getLinearIndexFromMatrix(i, i)];
    return product;
}

int MatrixXnX::productSecondaryDiag() const {
    int product = 1;
    for (int i = m_dim - 1; i >= 0; i--)
        product *= state[getLinearIndexFromMatrix(i, m_dim - 1 -i)];
    return product;
}

int MatrixXnX::sumRow(const int iRow) const {
    assert(iRow >= 0 && iRow < m_dim);
    int sum = 0;
    for (int i = 0; i < m_dim; i++)
        sum += state[getLinearIndexFromMatrix(iRow, i)];
    return sum;
}

int MatrixXnX::minColumn(const int iCol) const {
    assert(iCol >= 0 && iCol < m_dim);
    int min = state[getLinearIndexFromMatrix(0, iCol)];
    for (int i = 1; i < m_dim; i++)
        if (min > state[getLinearIndexFromMatrix(i, iCol)])
            min = state[getLinearIndexFromMatrix(i, iCol)];
    return min;
}

int MatrixXnX::maxColumn(const int iCol) const {
    assert(iCol >=0 && iCol < m_dim);
    int max = state[getLinearIndexFromMatrix(0, iCol)];
    for (int i = 1; i < 3; i++)
        if (max < state[getLinearIndexFromMatrix(i, iCol)])
            max = state[getLinearIndexFromMatrix(i, iCol)];
    return max;
}

int MatrixXnX::getLinearIndexFromMatrix(const int i, const int j) const {
    return i * m_dim + j;
}

int MatrixXnX::getDim() const {
    return m_dim;
}

MatrixXnX::~MatrixXnX() {
    delete[] state;
}
