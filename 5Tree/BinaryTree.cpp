#include <iostream>
using namespace std;

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

        void preorder() {
            cout << data << " ";
            if (lchild) {
                lchild->preorder();
            }
            if (rchild) {
                rchild->preorder();
            }
        }

        void inorder() {
            if (lchild) {
                lchild->inorder();
            }
            cout << data << " ";
            if (rchild) {
                rchild->inorder();
            }
        }

        void postorder() {
            if (lchild) {
                lchild->postorder();
            }
            if (rchild) {
                rchild->postorder();
            }
            cout << data << " ";
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

        void preorder() {
            root->preorder();
        }

        void inorder() {
            root->inorder();
        }

        void postorder() {
            root->postorder();
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
    binaryTree.preorder();
    cout << endl;
    binaryTree.inorder();
    cout << endl;
    binaryTree.postorder();
    cout << endl;
    return 0;
}