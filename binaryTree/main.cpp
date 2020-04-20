#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"

///Третьяков М. А. Группа РИ-280017

using namespace std;

void selectionSort(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void AddToTreeMiddleElement(BinaryTree& tree, const int* arrStart, int length) {
    if (length == 0)
        return;
    tree.Insert(*(arrStart + length / 2));
    AddToTreeMiddleElement(tree, arrStart, length / 2);
    AddToTreeMiddleElement(tree, arrStart + length / 2 + 1, length % 2 != 0 ? length / 2 : length / 2 - 1);
}

BinaryTree* CreateMinimalBST(const int* mas,const int start, const int end){
    auto tree = new BinaryTree();
    AddToTreeMiddleElement(*tree, mas, end);
    return tree;
}

int main() {
    BinaryTree tree;
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(5);
    tree.Insert(2);
    tree.Insert(1);
    tree.Insert(8);
    if(tree.Search(2))
        cout<< tree.Search(2)->GetValue()<< endl;
    delete &tree;
    int mas[] = {9, 10, 5, 1, 7};
    selectionSort(mas, sizeof(mas)/sizeof(mas[0]));
    auto minimalTree = CreateMinimalBST(mas, 0, sizeof(mas)/sizeof(mas[0]));
    int c;
    cin>>c;    
    delete minimalTree;
    return 0;
}
