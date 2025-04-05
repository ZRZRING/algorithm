#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,mp[1001][1001],dis[1000100],l[1000100],r[1000100],f[1001][1001],q;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void dfs(int node){
    for (int i=1;i<=n;i++){
        if (mp[node][i]>=0){
            l[node]=i;dis[i]=mp[node][i];
            mp[node][i]=-1;mp[i][node]=-1;
            dfs(i);break;
        }
    }
    for (int i=1;i<=n;i++){
        if (mp[node][i]>=0){
            r[node]=i;dis[i]=mp[node][i];
            mp[node][i]=-1;mp[i][node]=-1;
            dfs(i);break;
        }
    }
}
int dp(int node,int rest){
    if (rest==0)return 0;
    if (l[node]==0&&r[node]==0)return dis[node];
    if (f[node][rest])return f[node][rest];
    for (int k=0;k<=rest-1;k++){
        f[node][rest]=max(f[node][rest],dp(l[node],k)+dp(r[node],rest-k-1)+dis[node]);
    }
    return f[node][rest];
}
int main(){
    n=read();q=read();q++;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            mp[i][j]=-1;
        }
    }
    for (int i=1;i<=n-1;i++){
        int x=read(),y=read(),t=read();
        mp[x][y]=t;mp[y][x]=t;
    }
    dfs(1);printf("%d",dp(1,q));
    return 0;
}