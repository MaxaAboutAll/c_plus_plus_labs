#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"
#include <math.h>

///Третьяков М. А. Группа РИ-280017

using namespace std;

void bubbleSort(int *arr, int size) {
    int temp; 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

TreeNode* CreateMinimalBST(const int* mas, const int start, const int end){
    if(end < start)
        return nullptr;
    const int mid = (start + end) / 2;
    auto tree = new TreeNode(mas[mid]);
    tree->SetLeftNode(CreateMinimalBST(mas, start, mid - 1));
    tree->SetRightNode(CreateMinimalBST(mas, mid + 1, end));
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
    int mas[] = {9, 10, 5, 1, 7};
    bubbleSort(mas, sizeof(mas)/sizeof(mas[0]));
    BinaryTree minimalTree;
    minimalTree.SetRoot(CreateMinimalBST(mas, 0, sizeof(mas)/sizeof(mas[0]) - 1));
    int c;
    cin>>c;    
    return 0;
}
