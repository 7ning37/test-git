#include<iostream>
using namespace std;

class Dateinfo{
    private:
    int x,y;
    public:
    void set_date(int x,int y){
        this->x=x;
        this->y=y;
    }
    int RectHeight(int a,int b){
        return a>b?a-b:b-a;
    }

    int RectWidth(int a,int b){
        return a>b?a-b:b-a;
    }
};

/*int main(){
    Dateinfo s1,s1;
    s1.set_date()
}*/