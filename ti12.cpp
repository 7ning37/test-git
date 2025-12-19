#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;
    int height;
    int PI=3.14;
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
    int PI=3.14;
    double S=2*PI*radius*height+2*PI*radius*radius;
    cout<<"mianji="<<S<<endl;
}

void outputS(){
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
    c1.outputS();
    return 0;
}