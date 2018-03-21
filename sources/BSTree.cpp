#include<iostream>
#include "extra.h"
using namespace std;
using namespace BSTree;

Tree::Tree() { root = nullptr; }

bool Tree::insert(int value) {
    if (root == nullptr) {
        root = new Node{value, nullptr, nullptr};
        return true;
    }
    Node *current = root;
    while (1) {
        if (value > (current->data) && current->right != nullptr)
            current = current->right;
        else {
            if (value > (current->data) && ((current->right) = nullptr)) {
                current = new Node{value, nullptr, nullptr};
                return true;
            }
        }
        if (value < (current->data) && current->left != nullptr)
            current = current->left;
        else {
            if (value < (current->data) && ((current->left) = nullptr)) {
                current = new Node{value, nullptr, nullptr};
                return true;
            }
        }

    }
}
void Tree::printEl ( Node *node ,int a) {

    if (node == nullptr) {
        cout << "Tree is empty" << endl;
    } else {
        if (node->right != nullptr)
            printEl(node->right, a + 1);
        for (int i = 0; i < a; i++) {
            cout << "   ";
        }
        if ((node->data) != (root->data))
            cout << "-";
        cout << node->data << endl;
        if (node->left != nullptr)
            printEl(node->left, a + 1);
    }
}

void Tree::print() {
    printEl(root, 0);
}

void destroyTree ( Node *&node){
    if(node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    node=nullptr;
}

Tree::~Tree(){
    destroyTree(root);
};

