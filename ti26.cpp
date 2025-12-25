//6. (简答题)编程，输入一组产品检测数据，如：12.3, 11.6, 6.8, 22.3, 12.9, 5.6, 26.5, 2.4, 6.6, 19.8, 20.1, 13.2, ......，
//分别统计并输出(0,10]，(10,20]，(20,30]三个区间的数据个数。
#include<iostream>
using namespace std;
int main(){
    double arr[30];
    for(int i=0;i<30;i++){
        cout<<"请输入第"<<i+1<<"个元素：";
        cin>>arr[i];
    }
    int num1=0,num2=0,num3=0;
    for(int i=0;i<30;i++){
        if(arr[i]<=10&&arr[i]>0){
            num1++;
        }
        else if(arr[i]>10&&arr[i]<=20){
            num2++;
        }
        else if(arr[i]>20&&arr[i]<=30){
            num3++;
        }
    }
    cout<<"在(0,10]之间的元素个数为："<<num1<<endl;
    cout<<"在(0,20]之间的元素个数为："<<num2<<endl;
    cout<<"在(0,30]之间的元素个数为："<<num3<<endl;
    return 0;
}