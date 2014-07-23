#include<iostream>
using namespace std;
class Cell{//класс клеток зоопарка
public:
    int num;//номер клетки
    Cell(): num(0){}
    Cell(int n):num(n){ cout<<"Object Cell created:"<< num<<"\n";}
    void addCell(int num);
    virtual ~Cell(){};
};
void Cell::addCell(int num){
        while(num>0){
        new Cell(num);
        num--;}
};
class Pet{ //клас животных зоопарка
    public:
    int numberCell;//номер клетки
    Pet(): numberCell(0){}
    Pet(int n):numberCell(n){ cout<<"Object Pet created:"<< numberCell<<"\n";}
    void addPet(int num);
    virtual ~Pet(){};
};
void Pet::addPet(int num){
      while(num>0){
        new Pet(num);
        num--;}
}
class Compiler{//класс генерации зоопарка
private:
    int number;//number- количество питомцев
public:
    Compiler(int n):number(n){}
    virtual void compile();
};
void Compiler::compile(){
    Pet pet;
    pet.addPet(number);
    Cell cell;
    cell.addCell(number);
}
int main(void){
    int num;//количество питомцев зоопарка
    cout<<"how many cells the zoo?";
    cin>>num;
    Compiler newCompile(num);
    newCompile.compile();
    getchar();// нажатие
    getchar();// вывод
    return 0;
}
