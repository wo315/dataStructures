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

        ~Node() {
            if (lchild) {
                delete lchild;
            }
            if (rchild) {
                delete rchild;
            }
        }
};

class BinaryTree {
    private:
        Node* root;
    public:
        BinaryTree() {
            root = NULL;
        }

        ~BinaryTree() {
            delete root;
        }

        void build_demo(){
            root = new Node(1);
            root->lchild = new Node(2);
            root->rchild = new Node(3);
            root->lchild->lchild = new Node(4);
            root->lchild->rchild = new Node(5);
            root->rchild->rchild = new Node(6);
        }
};

int main() {
    BinaryTree binaryTree;
    binaryTree.build_demo();
    return 0;
}