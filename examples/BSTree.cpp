#include <iostream>
#include "extra.h"
#include <fstream>
using namespace std;
using namespace BSTree;


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
 const int g=11;
int main(int argc, char* argv[]) {
    int ch1=0;
    int arr[g];
    for (int i=0;i<g;i++){
        cin>>arr[i];
    }
    Tree tr;
    for ( int i=0 ;i<g ;i++){
        tr.insert(arr[i]) ;
    }
    int ch=0;
    bool is_done=false;
    while (!is_done) {
        choice();
        cin>>ch;
        switch(ch){
            case 1:
                tr.print();
                break;
            case 2:
                    cout << "1. Прямой обход"<< endl;
                    cout << "2. Поперечный обход" << endl;
                    cout << "3. Обратный обход" << endl;
                    cin >> ch1;
                    switch (ch1) {
                        case 1:
                            tr.direct();
                            cout<<endl;
                            break;
                        case 2:
                            tr.simmetric();
                            cout<<endl;
                            break;
                        case 3:
                            tr.back();
                            cout<<endl;
                            break;
                        default:
                            cout << "Неизвестная команда";
                    }
                    break;
            case 3:
                cout<<"введите число"<<endl;
                int chislo;
                cin>>chislo;
                tr.insert(chislo);
                break;
            case 4:
                break;
            case 5:
                tr.savetofile();
                break;
            case 6:
                tr.uploadfromfile();
                break;
            case 7:
                cout<<"введите число"<<endl;
                int n;
                cin>>n;
                if (tr.proverka_uzla(n))
                    cout<<"такой элемент присутствует "<<endl;
                else
                    cout<<"элемент не найден"<<endl;
                break;
            case 8: {
                if (endPr()) {
                    is_done = true;
                }
                break;
            }
            default:
                cout << "Неизвестная команда";
        }
    }
    return 0;
}
