#include<iostream>
using namespace std;

class Complex
{
private:
    double r;
    double i;
public:
    Complex():r(0.0),i(0.0){}
    Complex(double my_r,double my_i):r(my_r),i(my_i){}
    void show(){
        cout<<"the number of it is:"<<r<<endl;
        cout<<"the number of i is:"<<i<<endl;
    }
    Complex operator+(const Complex& p){
        Complex temp;
        temp.r=this->r + p.r;
        temp.i=this->i + p.i;
        return temp;
    }
};

int main()
{
    Complex s1(1.0,3.0),s2(2.5,3.5);
    //Complex s3=s1+s2;
    Complex s3=s1.operator+(s2);
    s1.show();
    s2.show();
    s3.show();
}
