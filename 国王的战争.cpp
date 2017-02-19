#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int mp[101][101];
int n,m,k;
struct pos{
int x,y;
}node[200];

bool canAtt(int x,int y){
 return x>=1&&x<=n&&y>=1&&y<=m;
}

void setRang(int x,int y){
    if(canAtt(x+1,y))mp[x+1][y]+=1;
    if(canAtt(x-1,y))mp[x-1][y]+=1;
    if(canAtt(x,y+1))mp[x][y+1]+=1;
    if(canAtt(x,y-1))mp[x][y-1]+=1;
    if(canAtt(x+1,y-1))mp[x+1][y-1]+=1;
    if(canAtt(x+1,y+1))mp[x+1][y+1]+=1;
    if(canAtt(x-1,y-1))mp[x-1][y-1]+=1;
    if(canAtt(x-1,y+1))mp[x-1][y+1]+=1;

}
void init(){
    memset(mp,0,sizeof(mp));
scanf("%d%d%d",&n,&m,&k);
for(int i=0;i<k;i++){
    cin>>node[i].x>>node[i].y;
    setRang(node[i].x,node[i].y);
}
}

void solve(){
    int flag = 1;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
    if(mp[i][j]>=2){flag=0;break;}
    if(!flag)break;
}
cout<<(flag?"YES":"NO")<<endl;

}
int main(){
init();
solve();
return 0;
}
