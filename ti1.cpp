//设计程序输出数列{An}的前50个数，输出时要求每行输出5个数。
//数列有下列规律：
//A1=1，A2=0.5，An+1=An（An-1+1）/（An+1)(n>=2)
#include<iostream>
using namespace std;                                
int main() {
    const int Num=50;
    double A[Num];
    A[0]=1.0;
    A[1]=0.5;
    for(int n=2;n<Num;n++){
        A[n]=A[n-1]*(A[n-2]+1)/(A[n-1]+1);
    }
    for(int i=0;i<Num;i++){
        cout<<A[i]<<" ";
        if((i+1)%5==0){
            cout<<endl;
        }
    }
    return 0;
}