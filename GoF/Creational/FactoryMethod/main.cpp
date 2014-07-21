#include<iostream>
using namespace std;
class Fence{//класс решётки клетки
public:
    int with;
    int heigt;
    string tupe;
    Fence(){ with=150;
             heigt=150;
             tupe="normal";
    cout<<"A Fence create\n";}
    Fence(char t[10]){
        with=150;
        heigt=150;
        tupe=t[10];
        cout<<"A Fence create\n";}
    //Деструктор
    virtual ~Fence(){cout<<"A Fence remove!!\n";}
};
class Cell{//клетка животного
public:
    int r1;
    int r2;
    int number;
    char pozition[10];
    void open(){}
    void close(){}
    void setSide(char variant[10]){
    pozition[10]= variant[10];}
    Cell(){}
    Cell(int n){
        r1=0;
        r2=0;
        number=n;
        cout<<"A Cell create\n";}
    //Деструктор
    virtual ~Cell(){cout<<"A Cell remove!!\n";}
};
class Zoo{
private:
    Cell* cell;
public:
    Zoo()//конструктор
    {cout<<"A Zoo create!!\n";}
    Zoo* addZoo(Cell* r){
        cell=r;//приравняли указатели на клетку
        return new Zoo;
    }
    //Деструктор
   virtual ~Zoo(){cout<<"A Zoo remove!!\n";}
};
class Door{//класс двери в клетку
public:
    Cell* x;
    Cell* y;
    int witch;
    int height;
    Door(){cout<<"A Door create!!";}
    Door(Cell* x1, Cell* y1): x(x1),y(y1)
    {cout<<"A Door create!!\n";}
    //Деструктор
    virtual ~Door(){cout<<"A Door remove!!\n";}
};
class MyZoo {//класс создания зоопарка
public:
    Zoo* CreateZoo();
    virtual Zoo* MakeZoo() const
    {return new Zoo;}
    virtual Fence* FenceZoo(char tup[10]) const
    {return new Fence(tup);}
    virtual Cell* CellZoo(int n) const
    {return new Cell(n);}
    virtual Door* DoorZoo(Cell* r1, Cell* r2) const
    {return new Door(r1,r2);}
    //Деструктор
    ~MyZoo(){cout<<"A MyZoo remove!!\n";}
};
Zoo* MyZoo::CreateZoo(){
    Zoo* myZoo=MakeZoo();
    Cell* r1=CellZoo(1);
    Cell* r2= CellZoo(2);
    Door* theDoor=DoorZoo(r1,r2);
    myZoo->addZoo(r1);
    myZoo->addZoo(r2);
    r1->setSide("South");
    r2->setSide("East");
    return myZoo;
}
int main(void){
    MyZoo object;//создадим пораждающий класс
   Zoo* zoo= object.CreateZoo();
   getchar();
   return 0;
}
