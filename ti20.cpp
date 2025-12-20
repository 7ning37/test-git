#include<iostream>
using namespace std;

class ThreeDShape
{
private: 
    int length;
    int width;
    int height;
    int V;

public:
    ThreeDShape():length(0),width(0),height(0){}
    ThreeDShape(int length,int width,int height){}
    
    void setCube(int length,int width,int height){
        this->length=length;
        this->width=width;
        this->height=height;
    }
    void volume(){
        V=length*width*height;
        cout<<"volume:"<<V<<endl;
    }
    void display(){
        cout<<"the length of the cft:"<<length<<endl;
        cout<<"the width of the cft:"<<width<<endl;
        cout<<"the height of the cft:"<<height;
    }
};

int main()
{
    
    int x0=1,y0=1,z0=1;
    ThreeDShape s1;
    s1.setCube(x0,y0,z0);
    cout<<"before change:"<<endl;
    s1.volume();
    s1.display();
    cout<<endl<<endl;
    int x,y,z;
    cout<<"please input length:";
    cin>>x;
    cout<<"please input width:";
    cin>>y;
    cout<<"please input height:";
    cin>>z;
    cout<<endl;
    cout<<"after change:"<<endl;   
    s1.setCube(x,y,z);
    s1.volume();
    s1.display();
}