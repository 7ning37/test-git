#include<iostream>
#include<string>
using namespace std;

class point
{
private:int a;int b;
public:
    point(int x,int y):a(x),b(y){}
    point(const point&p){
        a=p.a;b=p.b;
    }
    void diplay(){
        cout<<this->a<<b;
    }
};
int main(){
    point s1(1,3),s(2,4);
    point s1_(s1);
    s1.diplay();
    s1_.diplay();
    s.diplay();
    return 0;
}