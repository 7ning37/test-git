//编程，输出100~1000以内的所有素数，每行输出10个数，每个数字段宽度为5。
#include<iostream>
#include<cmath>
using namespace std;
bool panduan();

bool panduan(int n){
    if(n<2)return false;
    if(n==2)return true;
    else if(n%2==0)return false;
    for(int i=3;i<=sqrt(n);i+=2){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    int count=0;
    for(int i=100;i<1000;i++){
        if(panduan(i)){
            cout<<i<<" ";
            count++;
            if(count%5==0){
                cout<<endl;
            }
        }
    }
}