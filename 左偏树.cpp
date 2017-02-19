#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int maxn = 100000+10;
int father[maxn];
struct node{
int l,r;
int dis;
int strong;
}Ltree[maxn];

int find(int x){
if(x==father[x])return x;
return father[x] = find(father[x]);
}
int merge(int x,int y){
if(x==0)return y;
if(y==0)return x;
if(Ltree[x].strong<Ltree[y].strong)
swap(x,y);
Ltree[x].r = merge(Ltree[x].r,y);
int l = Ltree[x].l,r = Ltree[x].r;
father[r] = x;
if(Ltree[l].dis<Ltree[r].dis)
    swap(Ltree[x].l,Ltree[x].r);
if(Ltree[x].r == 0)Ltree[x].dis = 0;
else Ltree[x].dis = Ltree[Ltree[r]].dis+1;
return x;
}
int del(int x){
int l = Ltree[x].l,r = Ltree[x].r;
father[l]=l;
father[r] = r;
father[x] = Ltree[x].dis = Ltree[x].l = Ltree[x].r = 0;
return merge(l,r);
}

void solve(int x,int y){
Ltree[x].strong/=2;
Ltree[y].strong/=2;
int left = del(x);
int right = del(y);
left = merge(left,x);
right = merge(right,y);
left = merge(left,right);
printf("%d\n",Ltree[left].strong);
}
int main(){
int n;
while(scanf("%d",&n)!=EOF){
    for(int i=1;i<=n;i++){
        father[i] = i;
     scanf("%d",&Ltree[i].strong);
     Ltree[i].dis = Ltree[i].r = Ltree[i].r = 0;
    }
}
return 0;
}
