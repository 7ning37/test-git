//编程，计算sum = a + aa + aaa + aaaa + …+ aa…a（n个a），
//其中a是一位数字，a和n由键盘输入。
//如:若a = 3，n = 6，则sum = 3 + 33 + 333 + 3333 + 33333 + 333333，
//结果为：370368。
#include<iostream>
using namespace std;
int main(){
    int n,a,sum=0;
    cout<<"请输入位数a:";
    cin>>a;
    cout<<"请输入数字n:";
    cin>>n;
    int num=a;
    for(int j=0;j<n;j++){
        sum+=num;
        num=10*num+a;
        
    }
    cout<<"sum="<<sum;
    return 0;
}
/*#include<iostream>
using namespace std;
int main(void)
{
int i,a,n,sum = 0;
cout << "请输入a：";
cin >> a;
cout << "请输入n：";
cin >> n;
int Num = a;
for (i=1;i<=n;i++)
{
sum += Num;
Num=10*Num+a;
}
cout << "结果为:" << sum << endl;
return 0;
}*/
