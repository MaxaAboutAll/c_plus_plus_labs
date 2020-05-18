#ifndef ABSTRACT_MATRIX_MATRIXBASE_H
#define ABSTRACT_MATRIX_MATRIXBASE_H
#include <iostream>
#include <stdexcept>

class MatrixBase {
public:    
    MatrixBase() = delete;
    unsigned int size() const { return m_size; }
    void operator *= (int iMult);
    void operator += (MatrixBase& iAdd);
    virtual int element(unsigned int i, unsigned int j) const = 0;
    virtual int& element(unsigned int i, unsigned int j) = 0;
    friend std::ostream& operator<< (std::ostream &out, const MatrixBase &iMatrix);
protected:
    MatrixBase(unsigned int iSize) : m_size(iSize){}
    int getLinearIndexFromMatrix(unsigned int i, unsigned int j) const;
private:
    const unsigned int m_size;
};


#endif
