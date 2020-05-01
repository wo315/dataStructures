#include <iostream>

class Node {
    public:
        int data;
        Node* lchild;
        Node* rchild;
    
        Node(int _data) {
            data = _data;
            lchild = NULL;
            rchild = NULL;
        }
};

class BinaryTree {
    private:
        Node* tree;
    public:
        BinaryTree() {
            tree = NULL;
        }
};

int main() {
    BinaryTree binaryTree;
    return 0;
}