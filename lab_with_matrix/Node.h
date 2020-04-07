#ifndef LAB_WITH_MATRIX_NODE_H
#define LAB_WITH_MATRIX_NODE_H


class Node {
public:
    Node(int value);
    bool deleteNext();
    Node* getNext() const;
    int getValue() const;
    void setValue(int value);
    void push(Node* node);
    ~Node();
private:
    int Value;
    Node* Next = nullptr;    
};


#endif
