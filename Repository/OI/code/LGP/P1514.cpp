#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;
const int orz=500100;
const int gox[4]={0,0,1,-1};
const int goy[4]={-1,1,0,0};
int head[orz],n,m,cnt,mp[1001][1001],vis[1001][1001],ans,l[1001][1001],r[1001][1001];
struct node{
    int dis,id;
}a[orz];
inline int read(){
    int sym(0),res(0);char ch(0);
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int cmp(node a,node b){
    return a.dis>b.dis;
}
void dfs(int x,int y){
    vis[x][y]=1;
    for (int i=0;i<=3;i++){
        int tx=x+gox[i],ty=y+goy[i];
        if (mp[tx][ty]>=mp[x][y])continue;
        if (!vis[tx][ty])dfs(tx,ty);
        l[x][y]=min(l[x][y],l[tx][ty]);
        r[x][y]=max(r[x][y],r[tx][ty]);
    }
}
int main(){file();
    n=read();m=read();memset(l,0x3f,sizeof(l));
    memset(mp,0x7f,sizeof(mp));
    for (int i=1;i<=m;i++){
        l[n][i]=r[n][i]=i;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            mp[i][j]=read();
        }
    }
    for (int i=1;i<=m;i++){
        if (!vis[1][i])dfs(1,i);
    }
    int tot=0,flag=0;
    for (int i=1;i<=m;i++){
        if (!vis[n][i]){
            tot++;flag=1;
        }
    }
    if (flag){
        printf("0\n%d",tot);
    }else{
        int pl=1;
        while (pl<=m){
            int pr=0;
            for (int i=1;i<=m;i++){
                if (l[1][i]<=pl)pr=max(pr,r[1][i]);
            }cnt++;pl=pr+1;
        }
        printf("1\n%d",cnt);
    }
    return 0;
}