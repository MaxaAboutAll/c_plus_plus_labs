#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"
using namespace std;

int main() {
    Matrix2D matrix2D;
    Matrix3D matrix3D, matrix3D2;
    cout<<"matrix2D:\n"<<matrix2D<<endl;
    cout<<"matrix3D:\n"<<matrix3D<<endl;
    cout<<"matrix3D2:\n"<<matrix3D2<<endl;
    matrix2D *= 5;
    matrix3D2 += matrix3D;
    cout<<"matrix3D2 + matrix3D:\n"<<matrix3D2<<endl;
    cout<<"matrix2D * 5:\n"<<matrix2D<<endl;
    return 0;
}
