#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

void percolateDown(int a[],int hole,int size);
void heapSort(int a[],int size){

int tmp;
for(int i=size/2-1;i>=0;i--)
    percolateDown(a,i,size);
    for(int i=size-1;i>0;i--){
        tmp = a[0];a[0]=a[i];a[i]=tmp;//delete a[0]
        percolateDown(a,0,i);
    }
}

void percolateDown(int a[],int hole,int size){
int child;
int tmp = a[hole];
for(;hole*2+1<size;hole=child){

    child = hole*2+1;
    if(child!=size-1&&a[child+1]>a[child])
        child++;
    if(a[child]>tmp)a[hole]=a[child];
        else break;
}
a[hole]=tmp;
}


int main()
{
    int a[] = {3,1,4,5,7,6,9,8,0,2};
    heapSort(a,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
