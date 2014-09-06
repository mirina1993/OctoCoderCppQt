#include <iostream>
#include<string>
using namespace std;

int main()
{
    //определим 3ри объекта string
    string s1=("Meat");
    string s2="Fish";
    string s3;
    s3=s1;
    cout<<"s3= "<<s3<<endl;
    //используем перегруженную операцию +
    s3="Not "+s1+ ", not ";
    cout<<"s3= "<<s3<<endl;
    s3+=s2;
    //поменяем знаение двух слов
    s3.swap(s2);
    cout<<"s3= "<<s3<<endl;
    return 0;
}

