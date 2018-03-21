#include <iostream>
#include "BSTtree.cpp"
using namespace std;
using namespace BSTree;
const int a=15;


void choice(){
    cout<<"1. Вывести дерево на экран"<<endl;
    cout<<"2. Вывести список узлов дерева"<<endl;
    cout<<"3. Добавить узел в дерево"<<endl;
    cout<<"4. Удалить узел из дерева"<<endl;
    cout<<"5. Сохранить дерево в файл"<<endl;
    cout<<"6. Загрузить дерево из файла"<<endl;
    cout<<"7. Проверить наличие узла"<<endl;
    cout<<"8. Завершить работу программы"<<endl;

};

int main() {
    int b,c;
    int arr[a];
    for (int i=0 ; i<a; i++){
        cin>>b;
        arr[i]=b;
    }
    Tree *tr=new Tree;
    for ( int i=0 ;i<c ;i++){
        tr->insert(arr[i]) ;
    }
    int ch=0;
    while (1) {
        choice();
        cin>>ch;
        switch(ch){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                return 0;
        }
    }
    delete tr;
    return 0;
}
