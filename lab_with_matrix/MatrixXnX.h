#ifndef LAB_WITH_MATRIX_MATRIXXNX_H
#define LAB_WITH_MATRIX_MATRIXXNX_H


class MatrixXnX {
public:
    MatrixXnX(int iDim);
    int element(const int i, const int j) const;
    void setElement(const int i, const int j, const int value);
    void fillRandomElements(const int minVal, const int maxVal);
    int sumPrincipalDiag() const;
    int sumSecondaryDiag() const;
    int productPrincipalDiag() const;
    int productSecondaryDiag() const;
    int sumRow(const int iRow) const;
    int minColumn(const int iCol) const;
    int maxColumn(const int iCol) const;
    int getDim() const;
    ~MatrixXnX();
    MatrixXnX(const MatrixXnX&) = delete;
private:
    const int m_dim;
    int* state;
    int getLinearIndexFromMatrix(const int i, const int j) const;
};


#endif
