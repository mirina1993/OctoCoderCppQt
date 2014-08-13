#pragma warning (disable:4786)
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
//рассмотрела основы STL.
//контейнеры, алгоритмы и итераторы
//метод- применяется к контейнерам или категориям контейнеров
void testVector(){//последовательный контейнер вектор
    vector<int> v;
    v.push_back(34);//метод контейнера
    v.push_back(11);
    v.push_back(12);
    v[0]=3;
    v[1]=2;
    //вывод значений
    for(int i=0;i<v.size()/*метод контейнера*/;i++)
        cout<<"Create element konteiner VECTOR:"<<v[i]<<"\n";
    //очистим последовательный контейнер
    v.clear();
}
void testAsso(){//ассоциативный контейнер отображения
    string Town;
    string result;//результат поиска
    string town[]={"Saint-Petersburg","St.Petersburg","St. Petersburg","Moscow","Kazan","Yekaterinburg", "Yaroslivl","Nizhny Novgorod",
    "Novgorod","Ryazan","Voronezh","Vologda","Ivanovo","Samara","Rostov on Don", "Volgograd","Ufa",
    "Chelyabinsk","Omsk","Novosibirsk","Krasnoyarsk","Permian"};
    map<string, string, less<string> > mapTown;
    map<string, string, less<string> >::iterator iter;//итератор контейнера
    for(int i=0;i<18;i++)
        Town=
        mapTown[town[i]]=town[i];//заносим данные в отображение
    //поиск города
    cout<<"enter the name of the city en"<<endl;
    cin>>Town;
    result=mapTown[Town];
    if(result==Town)cout<<"Yes this Town!"<<endl;
    else{
    //вывод на экран
    for(iter=mapTown.begin(); iter!=mapTown.end();iter++)
        cout<<(*iter).first<<endl;
    getchar();
    }
    //очистим ассоциативный контейнер
    mapTown.clear();
}
int main(void){
    testVector();//реализация последовательного контейнера и его методов
    testAsso();
    getchar();
    return 0;
}
