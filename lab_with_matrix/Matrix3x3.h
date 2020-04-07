#ifndef LAB_WITH_MATRIX_MATRIX3X3_H
#define LAB_WITH_MATRIX_MATRIX3X3_H


class Matrix3x3 {
public:
    Matrix3x3();
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
private:
    int state[3][3];
};

#endif
