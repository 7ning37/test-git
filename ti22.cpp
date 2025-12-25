// 编程，计算1 + 22 + 333 + 4444 + … 的前n项的和，其中：1 n  9，n由键盘输入。如:若n = 3，则结果为：356。
#include <iostream>
using namespace std;
int main()
{
    int sum = 0;
    int n = 0;
    cout << "请输入n:";
    cin >> n;
    int a = 0;
    int num = 1, b;
    for (int i = 1; i <= n; i++)
    {
        a += num;
        num *= 10;
        b = i * a;
        sum += b;
    }
    cout << "sum=" << sum;
}

/*#include<iostream>
using namespace std;
int main(void)
{
int i, n, sum = 0, a = 1;
cout << "请输入n：";
cin >> n;
int Num =a;
for (i=1;i<=n;i++)
{
sum += Num;
a++;
Num=10*Num+a;
}
cout << "结果为:" << sum << endl;
return 0;
}
*/