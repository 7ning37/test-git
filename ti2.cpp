//从键盘输入一个整数，统计该数包含了多少个0
#include<iostream>
using namespace std;
int main()
{
    int num=0;
    int count=0;
    cout<<"请输入一个整数：";
    cin>>num;
    if(num==0){
        count=1;
    }else{
        while(num!=0){
            if(num%10==0){
                count++;
            }
            num=num/10;
        }
    }
    cout<<"该整数中包含"<<count<<"个0"<<endl;
    return 0;
}