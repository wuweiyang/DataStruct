/*
	Date: Thu Feb 16 2017 23:10:18 GMT+0800 (�й���׼ʱ��)
	Author: 0001
*/
/*
	Date: Thu Feb 16 2017 23:09:36 GMT+0800 (�й���׼ʱ��)
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
        for(int i=1;i<n;i++)//Ĭ�ϴӵڶ�λ��ʼ��dp[0]�Ѿ�����1
        {
            max=1;
            for(int j=0;j<=i-1;j++)
            {
                if(a[i]<a[j]&&dp[j]+1>max)//��ǰ�����ĸ߶Ȳ��ܸ���ǰ�ߵĵ���
                max=dp[j]+1;//��¼���������
            }
            dp[i]=max;//i����֮ǰ������ϣ�������ɵ���ĵݼ����г���
            if(max2<max) max2=max;//max2����¼dp�е��������Ҳ�������������
        }
        printf("%d\n",max2);
    return 0;
}
