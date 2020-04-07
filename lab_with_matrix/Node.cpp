#include "Node.h"

Node::Node(int value) {
    Value = value;
}

int Node::getValue() const {
    return Value;
}

Node* Node::getNext() const {
    return Next;
}

void Node::setValue(int value) {
    Value = value;
}

void Node::push(Node* node) {
    Node* tempNext = this;
    while(tempNext->Next != nullptr)
        tempNext = tempNext->Next;
    tempNext->Next = node;
}

bool Node::deleteNext() {
    if (Next == nullptr)
        return false;
    Node* temp = Next->getNext();
    Next->Next = nullptr;
    delete Next;
    Next = temp;
    return true;
}

Node::~Node() {
    delete Next;
}
