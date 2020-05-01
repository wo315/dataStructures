/*
    这个题目是已知先序遍历和中序遍历，然后求后序遍历。
    所以难点是Node类中，build函数的实现。肯定记不住。
*/

#include <iostream>
#include <string>
using namespace std;
using string;
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

        void postorder() {
            if (lchild) {
                lchild->postorder();
            }
            if (rchild) {
                rchild->postorder();
            }
            cout << data << " ";
        }

        Node *build(const string &pre_str, const string &in_str, int len) {
            Node *p = new Node(pre_str[0] - '0');
            int pos = in_str.find(pre_str[0]);
            if (pos > 0) {
                p->lchild = build(pre_str.substr(1, pos), in_str.substr(0, pos), pos);
            }
            if (len - pos - 1 > 0) {
                p->rchild = build(pre_str.substr(pos + 1), in_str.substr(pos + 1), len - pos - 1);
            }
            return p;
        }
};

class BinaryTree {
    private:
        Node* root;
    public:
        BinaryTree() {
            root = NULL;
        }

        BinaryTree(const string &pre_str, const string &in_str, int len) {
            root = root->build(pre_str, in_str, len);    
        }

        ~BinaryTree() {
            delete root;
        }

        void postorder() {
            root->postorder();
        }

        // void build_demo(){
        //     root = new Node(1);
        //     root->lchild = new Node(2);
        //     root->rchild = new Node(3);
        //     root->lchild->lchild = new Node(4);
        //     root->lchild->rchild = new Node(5);
        //     root->rchild->rchild = new Node(6);
        // }
};

int main() {
    string pre_str = "136945827";
    string in_str  = "963548127";
    BinaryTree binaryTree(pre_str, in_str, in_str.length());
    binaryTree.postorder();
    cout << endl;
    return 0;
}