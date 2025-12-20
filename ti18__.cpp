#include <iostream>
using namespace std;
#include <cstring>

class Book
{
private:
    char name[12];
    int number;
    int price;
    static int num;

public:
    Book(char*p,int my_number,int my_price):number(my_number),price(my_price){
        strcpy(name,p);
        num++;
    }
    Book(const Book& in){
        strcpy(name,in.name);
        number=in.number;
        price=in.price;
    }
    static int getnum(){
        return num;
    }
    int getprice(){
        return price;
    }
    int getnumbero(){
        return number;
    }
    char* getname(){
        return name;
    }
};
int Book::num=0;

int main()
{
    Book b1("C++",1,45);
    Book b2("C",2,40);
    Book b3("Math",3,30);
    cout<<b1.getname()<<" "<<b1.getnumbero()<<" "<<b1.getprice()<<endl;
    cout<<b2.getname()<<" "<<b2.getnumbero()<<" "<<b2.getprice()<<endl;
    cout<<b3.getname()<<" "<<b3.getnumbero()<<" "<<b3.getprice()<<endl;
    cout<<"The total number of books is:"<<Book::getnum()<<endl;
}