#include<iostream>
using namespace std;
class Zoo{
public:
    int number;
    Zoo(): number(0)
    {}
    Zoo* addZoo(Cell* r){
    return new Zoo;}
};
class Fence{
public:
    int witch;
    int height;
    Fence(): witch(150), height(150)
    {}
};
class Cell{
public:
    int r1;
    int r2;
    char pozition;
    void open(){}
    void close(){}
    void setSide(char variant){
    pozition= variant;}
    Cell(int n): r1(0), r2(0)
    {}
};
class Door{
public:
    Cell* x;
    Cell* y;
    int witch;
    int height;
    Door(Cell* x1, Cell* y1): x(x1),y(y1)
    {}
};
class MyZoo {
public:
    Zoo* CreateZoo();
    virtual Zoo* MakeZoo() const
    {return new Zoo;}
    virtual Fence* FenceZoo() const
    {return new Fence;}
    virtual Cell* CellZoo(int n) const
    {return new Cell(n);}
    virtual Door* DoorZoo(Cell* r1, Cell* r2) const
    {return new Door(r1,r2);}
};
Zoo* MyZoo::CreateZoo(){
    Zoo* myZoo=MakeZoo();
    Cell* r1=CellZoo(1);
    Cell* r2= CellZoo(2);
    Door* theDoor=DoorZoo(r1,r2);
    myZoo->addZoo(r1);
    myZoo->addZoo(r2);
    r1->setSide(N);
    r2->setSide(E);
    return myZoo;
}
