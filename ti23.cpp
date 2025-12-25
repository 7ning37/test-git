//3. (简答题)编程，计算以下分数序列的前30项之和:
//2/1,3/2,5/3,8/5......
#include<iostream>
using namespace std;
int main(){
    double count=0;
    double a=1,b=2;
    for(int i=0;i<30;i++){
        count+=b/a;
        int temp=b;
        b+=a;
        a=temp;
    }
    cout<<"count="<<count;
}
