#include<iostream>
using namespace std;
int countnum(int* Fibonacci,int n);

int main(){
    int* Fibonacci;
    int n;
    cout<<"please input n:";
    cin>>n;
    Fibonacci=new int[100];
    Fibonacci[0]=0;
    Fibonacci[1]=1;
    
    for(int i=2;i<100;i++){
        Fibonacci[i]=Fibonacci[i-1]+Fibonacci[i-2];
    }
    
    cout<<"number n:"<<Fibonacci[n-1]<<endl;
    int result=countnum(Fibonacci,n);
    cout<<"totalnumber:"<<result<<endl;
    delete[] Fibonacci;
    return 0;
}

int countnum(int* Fibonacci,int n){
    int count=0;
    for(int i=0;i<n;i++){
        count+=Fibonacci[i];
    }
    return count;
}