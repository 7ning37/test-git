#include<iostream>
using namespace std;

int* decomposition(int n,int* m_array);

int main(){
    int n;
    cout<<"n:";
    cin>>n;
    int* m_array[3];
    decomposition(n,*m_array);
    for(int i=0;i<3;i++){
        cout<<m_array[i]<<" ";
    }
}

int* decomposition(int n,int* m_array){
    m_array[0]=n/100;
    m_array[1]=n%100/10;
    m_array[2]=n%10;
    return m_array;
}