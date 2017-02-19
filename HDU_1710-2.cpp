
#include <iostream>
using namespace std;
int pre[1005],mid[1005];
void printpost(int start1, int start2, int size, bool flag)
{
    if(size==1)
    {
        printf("%hd ",pre[start1]);
        return;
    }
    else if(size<=0)
        return;
    int i;
    for(i=0;i<size && pre[start1]!=mid[start2+i];i++) ;
    printpost(start1+1,start2,i,false);
    printpost(start1+i+1,start2+i+1,size-i-1,false);
    if(flag)
        printf("%d/n",pre[start1]);
    else
        printf("%d ",pre[start1]);
}
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&pre[i]);
        for(i=0;i<n;i++)
            scanf("%d",&mid[i]);
        printpost(0,0,n,true);
    }
    return 0;
}
