#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;
struct node {
int x;
node *l,*r;
};
const int maxn = 10000;
node *root;
int in[maxn],pre[maxn];
node *create(int *pre,int *in,int n){
    node *tmp ;
for(int i=0;i<n;i++)
if(pre[0]==in[i]){
    tmp=(node *)malloc(sizeof(node));
    tmp->x = in[i];
    tmp->l = create(pre+1,in,i);
    tmp->r = create(pre+i+1,in+i+1,n-i-1);
    return tmp;
    }
    return NULL;
}

void solve(node * t,int s){
    if(s==t->x){printf("\n");return;}
if(s<t->x){
    printf("E");
    solve(t->l,s);
}
else if (s>t->x){
    printf("W");
    solve(t->r,s);
}
}
int main()
{
for(int i=0;i<maxn;i++)
    in[i]=i+1;
int T,n,q;
scanf("%d",&T);
while(T--){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",pre+i);
    root=create(pre,in,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
     int x;
     cin>>x;
     solve(root,x);
    }
}
    return 0;
}
