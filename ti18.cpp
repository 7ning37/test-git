#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string name;
    int number;
    float price;
    static int num;

public:
    Book() : name(""), number(0), price(0.0) {}
    void setname(string my_name)
    {
        name = my_name;
        num++;
    }
    void setnumber(int my_number)
    {
        number = my_number;
    }
    void setprice(float my_price)
    {
        price = my_price;
    }
    void showinformation()
    {
        cout << "The name of the book is:" << name << endl;
        cout << "The number of the book is:" << number << endl;
        cout << "The price of the book is:" << price << endl;
    }
    void countbook()
    {
        cout << "the total number of books is:" << num << endl;
    }
};
int Book::num = 0;

int main()
{
    Book s1,s2,s3;
    string name1,name2,name3;
    int number1,number2,number3;
    float price1,price2,price3;
    cout<<"Input the information of book 1:"<<endl;
    cout<<"name:";
    cin>>name1;
    cout<<"number:";
    cin>>number1;
    cout<<"price:";
    cin>>price1;
    s1.setname(name1);
    s1.setnumber(number1);
    s1.setprice(price1);
    s1.showinformation();
    cout<<"\n";
    cout<<"Input the information of book 2:"<<endl;
    cout<<"name:";
    cin>>name2;
    cout<<"number:";
    cin>>number2;
    cout<<"price:";
    cin>>price2;
    s2.setname(name2);
    s2.setnumber(number2);
    s2.setprice(price2);
    cout<<"\n";
    cout<<"Input the information of book 3:"<<endl;
    cout<<"name:";
    cin>>name3;
    cout<<"number:";
    cin>>number3;
    cout<<"price:";
    cin>>price3;
    s3.setname(name3);
    s3.setnumber(number3);
    s3.setprice(price3);
    cout<<endl;
    s1.showinformation();
    cout<<endl;
    s2.showinformation();
    cout<<endl;
    s3.showinformation();
    cout<<endl;
    s3.countbook();
}