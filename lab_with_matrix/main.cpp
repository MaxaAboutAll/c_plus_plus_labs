#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include "Matrix3x3.h"
#include "MatrixXnX.h"
#include "Node.h"

using namespace std;

void PrintMatrix3x3(Matrix3x3 matrix3X3){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << matrix3X3.element(i, j) << "\t";
        cout << endl;
    }
}

void PrintMatrixXnX(MatrixXnX& matrixXnX){
    for (int i = 0; i < matrixXnX.getDim(); ++i) {
        for (int j = 0; j < matrixXnX.getDim(); ++j)
            cout << matrixXnX.element(i, j) << "\t";
        cout << endl;
    }
}

void WorkMatrix3x3(){
    Matrix3x3 matrix3X3;
    PrintMatrix3x3(matrix3X3);
    matrix3X3.fillRandomElements(-15, 15);
    PrintMatrix3x3(matrix3X3);
    cout<< "productPrincipalDiag " << matrix3X3.productPrincipalDiag()<<endl;
    cout<<"productSecondaryDiag " << matrix3X3.productSecondaryDiag()<<endl;
    cout<<"sumPrincipalDiag " << matrix3X3.sumPrincipalDiag()<<endl;
    cout<<"sumSecondaryDiag " << matrix3X3.sumSecondaryDiag()<<endl;
    for (int i = 0; i < 3; ++i)
        cout<<"sumRow " << matrix3X3.sumRow(i)<<endl;
    for (int i = 0; i < 3; ++i)
        cout<<"minColumn " << matrix3X3.minColumn(i)<<endl;
    for (int i = 0; i < 3; ++i)
        cout<<"maxColumn " << matrix3X3.maxColumn(i)<<endl;
}

void WorkMatrixXnX(){
    int iDim = 3;
    MatrixXnX matrixXnX(iDim);
    PrintMatrixXnX(matrixXnX);
    matrixXnX.fillRandomElements(0, 15);
    PrintMatrixXnX(matrixXnX);
    cout<< "productPrincipalDiag " << matrixXnX.productPrincipalDiag()<<endl;
    cout<<"productSecondaryDiag " << matrixXnX.productSecondaryDiag()<<endl;
    cout<<"sumPrincipalDiag " << matrixXnX.sumPrincipalDiag()<<endl;
    cout<<"sumSecondaryDiag " << matrixXnX.sumSecondaryDiag()<<endl;
    for (int i = 0; i < iDim; ++i)
        cout<<"sumRow " << matrixXnX.sumRow(i)<<endl;
    for (int i = 0; i < iDim; ++i)
        cout<<"minColumn " << matrixXnX.minColumn(i)<<endl;
    for (int i = 0; i < iDim; ++i)
        cout<<"maxColumn " << matrixXnX.maxColumn(i)<<endl;
}

bool checkVectorContains(vector<int> vector, int value){
    for (int i = 0; i < vector.size(); ++i) 
        if (vector[i] == value)
            return true;
    return false;
}

void DeleteDuplicateInLinkedList(Node& root){
    vector<int> a;
    Node* cursor = &root;
    a.push_back(cursor->getValue());
    while (cursor->getNext()){
        if (checkVectorContains(a, cursor->getNext()->getValue())){
            cursor->deleteNext();
            continue;
        }
        a.push_back(cursor->getNext()->getValue());
        cursor = cursor->getNext();
    }
}

void FindKElementFromEnd(Node& list, int k){
    int count = 0;
    Node* head = &list;
    while (head != nullptr){
        count++;
        head = head->getNext();
    }
    assert(k < count);
    head = &list;
    for (int i = 0; i < count - k; i++) {
        head = head->getNext();
    }
    cout << head->getValue() <<endl;
}

void PrintList(Node& list){
    Node* head = &list;
    while (head != nullptr){
        cout << head->getValue()<<" ";
        head = head->getNext();
    }
    cout<<endl;
}

int main() {
    WorkMatrix3x3();
    WorkMatrixXnX();
    Node startNode = Node(5);
    for(int i = 0; i< 5; i++){
        startNode.push(new Node(i));        
        startNode.push(new Node(i%3));
    }
    startNode.push(new Node(2));
    startNode.push(new Node(2));
    startNode.push(new Node(2));
    startNode.push(new Node(2));
    PrintList(startNode);
    DeleteDuplicateInLinkedList(startNode);
    PrintList(startNode);
    FindKElementFromEnd(startNode, 5);
    return 0;
}
