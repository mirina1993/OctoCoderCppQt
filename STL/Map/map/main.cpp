#pragma warning (disable:4786)
#include <iostream>
#include<string>
#include<map>
using namespace std;
//программа подсчёта введённых слов
void request(string &word){
    cout<<"Enter word: ";
    cin>>word;
}
void print(map<string,int> &words){
    map<string,int>::iterator iter;
    cout<<"\nContainer values are sorted by key."<<endl;
    cout<<"Enter word(key)______number word"<<endl;
    for(iter=words.begin();iter!=words.end();iter++)
        cout<<""<<(*iter).first<<" "<<(*iter).second<<endl;
}
void initialization(map<string,int> &words){
    string result;
    cout<<"To exit, type 'exit' "<<endl;
    request(result);
    int i=1;
    while(result!="exit"){
        words[result]=i;
        i++;
        request(result);
    }
}
int main()
{
    map<string,int> words;//string-ключи
                                        //int-тип значений контейнера
                                        //less<string>-сортировка ключей по алфавиту
    cout<<"Hi user!"<<endl;
    //заполнение отображения
    initialization(words);
    //вывод на печать значений отображения
    print(words);
    //очистим контейнер
    words.clear();
    getchar();
    return 0;
}

