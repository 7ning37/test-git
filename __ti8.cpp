#include<iostream>
using namespace std;
#include<ctime>
#define N 100

void sort(int* a,int size);
int findMid(int* a,int size);

void main(){
    int i,aa[N]={0};
    srand((unsigned)time(0));
    for(i=0;i<N;i++){
        aa[i]=rand()%1000;
    }
}
//不允许void main（）函数
