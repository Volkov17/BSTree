#include <iostream>
#include "extra.h"
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

bool endPr(){
    string ch;
    while (1){
        cout<<"Вы уверены, что хотите выйти из программы ? (да|нет) (yes|no)";
        cin >> ch;
        if ((ch =="yes") || (ch=="да")) {
            return true;
        }
        else {
            if ((ch == "no") || (ch=="нет") )
                return false;
        }
    }
}

int main() {
    int ch1=0;
    int arr[a];
    for (int i=0;i<a;i++){
        cin>>arr[a];
    }
    Tree *tr=new Tree;
    for ( int i=0 ;i<a ;i++){
        tr->insert(arr[i]) ;
    }
    int ch=0;
    delete tr;
    while (1) {
        choice();
        cin>>ch;
        switch(ch){
            case 1:
                tr->print();
                break;
            case 2:
                    cout << "a. Прямой обход"<< endl;
                    cout << "b. Поперечный обход" << endl;
                    cout << "c. Обратный обход" << endl;
                    cin >> ch1;
                    switch (ch1) {
                        case 'a':
                            tr->direct();
                            cout << endl;
                            break;
                        case 'b':
                            tr->simmetric();
                            cout << endl;
                            break;
                        case 'c':
                            tr->back();
                            cout << endl;
                            break;
                    }
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
                if (endPr()) {
                    tr->~Tree();
                    return 0;
                }
                else
                    continue ;

        }
    }
    return 0;
}
