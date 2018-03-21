
#include<iostream>
namespace BSTree {
    struct Node {
        int data;
        Node *left;
        Node *right;
//        Tree *p;
    };

    class Tree {
        Node *root;
        void printEl(Node* node, int a);
        void destroyTree(Node*&node) ;
    public:
        Tree();
        bool insert(int value);
        void print() ;
        ~Tree();
    };
}

