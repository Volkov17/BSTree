#include<iostream>
#include "extra.h"
#include <fstream>
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
        if (value > (current->data) && current->right != nullptr){
            current = current->right;
            continue;
        }
        else {
            if (value > (current->data) && ((current->right) == nullptr)) {
                current->right = new Node{value, nullptr, nullptr};
                return true;
            }
        }
        if (value < (current->data) && current->left != nullptr){
            current = current->left;
            continue;
        }
        else {
            if (value < (current->data) && ((current->left) == nullptr)) {
                current->left = new Node{value, nullptr, nullptr};
                return true;
            }
        }
    }

}


void Tree::printEl ( Node *node ,int ch) {
    if (node == nullptr) {
        cout << "Tree is empty" << endl;
    } else {
        if (node->right != nullptr)
            printEl(node->right, ch + 1);
        for (int i = 0; i < ch; i++) {
            cout << "   ";
        }
        if ((node->data) != (root->data))
            cout << "-";
        cout << node->data << endl;
        if (node->left != nullptr)
            printEl(node->left, ch + 1);
    }
}

void Tree::print() {
    printEl(root, 0);
}

void Tree::SimmetricGo(Node* node) {
    if (node) {
        SimmetricGo(node->left);
        cout<< node->data<<' ';
        SimmetricGo(node->right);
    }
}

void Tree::simmetric()  {
    SimmetricGo(root);
}


void Tree::DirectGo(Node* node) {
    if (node) {
        cout<<node->data<<' ';
        DirectGo(node->left);
        DirectGo(node->right);
    }
}

void Tree::direct()  {
    DirectGo(root);
}

void Tree::BackGo(Node* node) {
    if (node) {
        BackGo(node->left);
        BackGo(node->right);
        cout << node->data<<' ';
    }
}
void Tree::back()  {
    BackGo(root);
}

void Tree::destroyTree ( Node *node){
    if(node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    node=nullptr;
}

void Tree::save_tree(ofstream &f, Node *node){
    if (node != nullptr) {
        f << node->data << " ";
        save_tree(f,node->right);
        save_tree(f,node->left);
    }
}

void Tree::infileEl(Node*node){
    ofstream fout;
    fout.open("BinTree.txt");
    if(!fout.is_open() || root == nullptr)
        cout << "error" << endl;
    save_tree(fout,root);
}

void Tree::savetofile(){
    infileEl(root);
}

void Tree::fromfileEl(){
    ifstream File("BinTree.txt");
    if (!File.is_open())
        cout<<"error";
    if(root) {
        destroyTree(root);
    }
    int a;
    root=nullptr;
    while(File >> a) {
        insert(a);
    }
}
void Tree::uploadfromfile() {
    fromfileEl();
}

bool Tree::proverka_uzla(int n){
    Node * current =root;
    while(current !=nullptr){
        if (current->data==n)
            return true;
        else {
            if (current->data<n)
                current=current->right;
            else
                current=current->left;
        }
    }
}

Tree::~Tree(){
    destroyTree(root);
};


