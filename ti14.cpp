#include<iostream>
#include<cmath>
using namespace std;

class NUM{
private:
int m;//m为下限
int n;//n为上限
int num;//num为存放指定范围内素数的数量
int arr[50];
public:
NUM():m(0),n(0),num(0){}
NUM(int a,int b):m(a),n(b),num(0){}  

int isprime(int sum){
    if(sum<2)return 0;
    else if(sum==2)return 1;
    else if(sum%2==0)return 0;
    for(int i=3;i<=sqrt(sum);i+=2){
        if(sum%i==0)return 0;
    }
    return 1;
}

void save(){
    int count=0;
    for(int i=m;i<n;i++){
        if(isprime(i)){
            arr[count]=i;
            count++;
        }
    }
}

void print(int num){
    for(int i=0;i<num;i++){
        cout<<arr[num-i-1]<<" ";
        if((i+1)%5==0){
            cout<<endl;
        }
    }
}

};

int main(){
    int m,n,num,z;
    cout<<"input m=";
    cin>>m;
    cout<<"input n=";
    cin>>n;
    cout<<"input num=";
    cin>>num;
    NUM test(m,n);
    test.isprime(z);
    test.save();
    test.print(num);
    return 0;
}