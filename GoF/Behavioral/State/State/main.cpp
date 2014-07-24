#include <iostream>

using namespace std;
class Shop{
public:
    void print(){
      cout << "Variant Shop"<<endl;
    }
};
class Zoo{
public:
    void print(){
      cout << "Variant Zoo"<<endl;
    }
};
class Visiter{//класс посетителя
public:
    char name[25];
    char variant;
};
class Choice{//класс возможного выбора
private:
    Visiter *man;
    Zoo zoo;
    Shop shop;
public:
    Choice( Visiter &one):man(&one){cout << "Hi!"<<man->name<<endl;}
    void variant(){
        if('Z'==man->variant){zoo.print();}
        if('S'==man->variant){shop.print();}
    }
};
int main()
{
    Visiter guest;
    cout << "Hello vvidite name"<<endl;
    cin>>guest.name;
    cout << "When do you go zoo-'Z' or shop-'S'?"<< endl;
    cin>>guest.variant;
    cout << "Hello"<<guest.name << endl;
    Choice choice(guest);
    choice.variant();
    getchar();
    return 0;
}

