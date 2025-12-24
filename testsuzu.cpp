#include<iostream>
#include<iomanip>
#define S "china"
using namespace std;
int main()
{
    /*int arr[4];
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(arr[0])<<endl;
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    cout<<S<<endl;*/
    int a[5]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<setw(4)<<a[i];
    } 
    return 0;
}
    