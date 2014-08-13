#include<iostream>
#include <iostream>
#include<set>
#include<string>
//#pragma warning(disable:4786)
using namespace std;
void initialization(set<string> &plant){
    int number;
    cout<<"Enter the number of flowers in a bouquet: ";
    cin>>number;
    string array[]={"aster","calla","camomile","cactus","chrysanthemum","dahlia",
                    "forget-me-not","geatsint","geranium","gladiolus","marguerite",
                    "orchid","poppy","peony","rose","tulip","violet"};
    set<string>::iterator iter;
    if(number>0&&number<18){
        for(int i=0;i<number;i++)
                plant.insert(array[i]);
        iter=plant.begin();
        //вывод множества
        while(iter!=plant.end())
            cout<<*iter++<<endl;
    }
    else cout<<"Error range!"<<endl;
}
//методы поиска используемые только для ассоциативных контейнеров
void search(set<string> &plant){
    set<string>::iterator iter;
    //зададим начало и конец диапазона
    string begin, end;
    cout<<"\n"<<"Enter the range, example: c czz ";
    cin>>begin>>end;
        iter=plant.lower_bound(begin);
        if(iter!=plant.end()){
             while(iter!=plant.upper_bound(end))
                 cout<<*iter++<<endl;
         }
         else cout<<"Error range!"<<endl;
         getchar();
}
int main()
{
    //создадим множество
    set<string> flowers;
    //инициализация множества
    initialization(flowers);
    //поиск
    search(flowers);
    //очистим контейнер
    flowers.clear();
    getchar();
    return 0;
}
