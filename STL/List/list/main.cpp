#include<iostream>
#include<list>
using namespace std;
void functionList(list<int> &list1,list<int> &list2,int num){//передаём в функцию число элементов для добавления в список
    list<int>:: iterator iter;
    while(num>0){
        list1.push_back(num);//добавление данных в конец
        list2.push_front(num+4);//добавление данных в начало
        num--;
    }
    //метод объединения двух списков
    list1.reverse();//merge работает с сортированными контейнерами
    list1.merge(list2);
    //контейнер list не имеет произвольного доступа, т.е. операция[] невозможна
    //воспользуемся итератором для вывода данных
    for(iter=list1.begin();iter!=list1.end();iter++){
        cout<<""<< *iter<<endl;
    }
}
int main(void){
    list<int> list1;//создаём список из элементв типа int
    list<int> list2;//создаём список из элементв типа int
    int number;//число добавления элементов в список
    cout<<"vvedite shislo: ";
    cin>>number;
    //заполнение данными и печать списка
    functionList(list1, list2, number);
    //очистим оба контейнера
    list1.clear();
    list2.clear();
    getchar();
    return 0;
}
