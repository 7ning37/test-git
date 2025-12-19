#include <iostream>
#include<iomanip>
using namespace std;

class Circle
{
private:
    int radius;
    int height;
    const double PI=3.14;
    double S;
public:
void set_raadius(int my_radius){
    radius=my_radius;
}

void set_height(int my_height){
    height=my_height;
}

void get_radius(){
    cout<<"radius="<<radius<<endl;
}

void get_height(){
    cout<<"height"<<height<<endl;
}

void inputS(int radius){
    double S=2*PI*radius*height+2*PI*radius*radius;
    cout<<"surface S="<<S<<endl;
}

};

int main(){
    Circle c1;
    int x,y;
    cout<<"input radius:";
    cin>>x;
    cout<<"input height:";
    cin>>y;
    c1.set_raadius(y);
    c1.set_height(x);
    c1.get_radius();
    c1.get_height();
    c1.inputS(x);
    return 0;
}