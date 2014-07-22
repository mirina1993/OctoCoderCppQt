#include<iostream>
using namespace std;
static int number=0;//номера клеток для построения дерева
class Cell{//класс клеток зоопарка
public:
    int number;
    string name;
    Cell(): number(0){}
    Cell(int n, string s):number(n), name(s){}
    virtual ~Cell(){};
};
class Tree{ //клас построения списка поиска клетки
public:
    int count;//количество ветвлений, уровней дерева
    Tree* p1;
    Tree* p2;
    Tree(): count(0){}
    Tree(int n): count(n){}
    virtual void add(int n);
    virtual void remove();
    virtual ~Tree(){};
};
void Tree::add(int n){
    if(n==1){
        p1=NULL;
        p2=NULL;}
    else{
        p1=new Tree(n-1); cout<<"Object created:"<< number<<"\n";
        p2=new Tree(n-1);cout<<"Object created:"<< number<<"\n";}
    number++;
};
void Tree::remove(){
    delete p1;cout<<"Object deleted:"<< number<<"\n";
    delete p2;cout<<"Object deleted:"<< number<<"\n";
};
class Visitor{//посетитель зоопарка
public:
    string name;
    int age;
    Visitor(){}
    Visitor(string n, int a): name(n), age(a){}
    virtual void parse(Tree&){}
    virtual ~Visitor(){};
};
class Compiler{//класс представляющий интерфейс для доступа к системе зоопарка
public:
    virtual void compile(int number);//number- количество требуемых клеток
};
void Compiler::compile(int number){
    Visitor person;
    int num=number;
    for(int i=0; i<=num; number--){
        new Cell(i, "cell"+i);
        i++;
        num--;}
    Tree tre(number);

}
int main(void){
    Compiler newCompile;
    cout<<"how many cells the zoo?";
    cin>>number;
    getchar();
    return 0;
}

