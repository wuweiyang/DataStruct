#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=1010;
struct Tree{
Tree *l,*r;
int x;
};

Tree *root;
Tree * create(int *pre,int *in,int n){
Tree *tmp;
for(int i=0;i<n;i++)
{
 if(pre[0]==in[i])
 {
  tmp = (Tree *)malloc(sizeof(Tree));
  tmp->x = in[i];
  tmp->l = create(pre+1,in,i);
  tmp->r = create(pre+1+i,in+i+1,n-(i+1));
  return tmp;
 }
}
return NULL;
}

void postOrder(Tree *rt){
if(rt!=NULL){
    postOrder(rt->l);
    postOrder(rt->r);
    if(rt!=root)
        printf("%d ",rt->x);
    else
        printf("%d\n",rt->x);
    }
}
int main()
{
    int n,pre[N],in[N];
    while(~scanf("%d",&n)){
        root = NULL;
        for(int i=0;i<n;i++)
        scanf("%d",pre+i);
        for(int j=0;j<n;j++)
            scanf("%d",in+j);
        root = create(pre,in,n);
        Tree *rt = root;
        postOrder(rt);
    }
    return 0;
}
