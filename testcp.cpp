//编程，定义“一维数组”类，找出数组中的最大值和最小值；然后编写主函数进行测试
#include <iostream>
#include<string>
using namespace std;
class Number
{
private:
    int max;
    int min;
    int size;
    int* arr;
public:
    Number():max(0),min(0),size(0),arr(NULL){}
    ~Number(){
        if(arr!=NULL){
            delete[] arr;
        }
    }
    void inputarr(){
        cout<<"数组的长度n为:";
        cin>>size;
        if(size<=0){
            cout<<"数组不存在"<<endl;
        }
        else{
            arr=new int[size];
            for(int i=0;i<size;i++){
                cout<<"第"<<i+1<<"个元素为：";
                cin>>arr[i];
            }
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        }
    }
    void countmax(){
        max=arr[0];
        for(int i=0;i<(size-1);i++){
            if(arr[i]<arr[i+1]){
                max=arr[i+1];
            }
        }
        cout<<"最大值为："<<max<<endl;
    }
        void countmin(){
        min=arr[0];
        for(int i=0;i<(size-1);i++){
            if(arr[i]>arr[i+1]){
                min=arr[i+1];
            }
        }
        cout<<"最小值为："<<min<<endl;
    }
};

int main()
{
    Number s1;
    s1.inputarr();
    s1.countmax();
    s1.countmin();
    return 0;
}