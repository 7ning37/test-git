#include<iostream>
#include<cstring>
using namespace std;

class Book
{
    char name[12];
    int id;
    float price;
    static int num;
public:
    Book(char*p,int id,float f):id(id),price(f)
    {
        strcpy(name,p);
        num++;
    }
    Book(const Book& in){
        strcpy(name,in.name);
        id=in.id;
        price=in.price;
    }
    static int getnum(){
        return num;
    }
    float getprice(){
        return price;
    }
    char* getname(){
        return name;
    }
};
int Book::num=0;
int main()
{
    Book b1("C++",1,45.2);
    Book b2("C",2,40.0);
    Book b3("Math",3,30.0);
    cout<<b1.getname()<<" "<<b1.getprice()<<endl;
    cout<<b2.getname()<<" "<<b2.getprice()<<endl;
    cout<<b3.getname()<<" "<<b3.getprice()<<endl;
    cout<<"The total number of books is:"<<Book::getnum()<<endl;
}