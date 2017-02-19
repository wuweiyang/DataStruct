/*
	Date: Thu Feb 16 2017 23:10:18 GMT+0800 (中国标准时间)
	Author: 0001
*/
/*
	Date: Thu Feb 16 2017 23:09:36 GMT+0800 (中国标准时间)
	Author: 0001
*/
#include<stdio.h>
#include<string.h>
int dp[1010],a[1010];
int main()
{
    int t,n;

        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        int max,max2;
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        max2=0;
        dp[0]=1;
        for(int i=1;i<n;i++)//默认从第二位开始，dp[0]已经等于1
        {
            max=1;
            for(int j=0;j<=i-1;j++)
            {
                if(a[i]<a[j]&&dp[j]+1>max)//当前导弹的高度不能高于前边的导弹
                max=dp[j]+1;//记录最大拦截数
            }
            dp[i]=max;//i与它之前的数组合，所能组成的最长的递减序列长度
            if(max2<max) max2=max;//max2来记录dp中的最大数，也就是最大拦截数
        }
        printf("%d\n",max2);
    return 0;
}
