#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int divide(int a[],int low,int high){
int k = a[low];
do {
    while(low<high&&a[high]>=k)high--;
    if(low<high){a[low]=a[high];++low;}
    while(low<high&&a[low]<=k)++low;
    if(low<high){a[high]=a[low];high--;}
}while(low!=high);
a[low]=k;
return low;
}

void quickSort(int a[],int low,int high){
int mid;
if(low>=high)return;
mid = divide(a,low,high);
quickSort(a,low,mid-1);
quickSort(a,mid+1,high);
}

void quickSort(int a[],int size){
quickSort(a,0,size);
}
int main()
{
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    quickSort(a,10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
