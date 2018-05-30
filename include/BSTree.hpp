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
        void destroyTree(Node*node) ;
        void DirectGo(Node* node);
        void SimmetricGo(Node* root);
        void BackGo(Node* root);
        void infileEl(Node*root);
        void fromfileEl();
        void save_tree(std::ofstream &File,  Node * root);

    public:
        Tree();
        bool insert(int value);
        void print() ;
        void direct();
        void simmetric();
        void back();
        void savetofile();
        void uploadfromfile();
        bool proverka_uzla(int n);
        ~Tree();
    };
}




