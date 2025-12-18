//
#include<iostream>
using namespace std;

int func(int n);

int main(){
    int n;
    cout<<"n:";
    cin>>n;
    int result=func(n);
    cout<<"result: "<<result<<endl;
    return 0;
}

int func(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(i%5==0&&i%11==0){
            sum+=i;
        }
    }
    return sum*sum;
}