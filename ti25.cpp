/*编程，输出如下图形：
              *******
               *****
                ***
                 *
                ***
               *****
              *******            */
#include<iostream>
using namespace std;
int main(){
    for(int i=4;i>0;i--){
        for(int j=i;j<4;j++){
            cout<<" ";
        }
        for(int j=2*i-1;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<4;i++){
        for(int j=i;j<3;j++){
            cout<<" ";
        }
        for(int j=2*i+1;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}/*
#include<iostream>
using namespace std;
int main(){
    cout<<"*******"<<endl;
    cout<<" *****"<<endl;
    cout<<"  ***"<<endl;
    cout<<"   *"<<endl;
    cout<<"  ***"<<endl;
    cout<<" *****"<<endl;
    cout<<"*******"<<endl;
    return 0;
}*/