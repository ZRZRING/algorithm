#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m;
struct EDGE{
    int ver,nxt,pre;
}edge[N];
int head[N],cnt,dp[N];
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
int dfs(int u,int last,int t){
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==last)continue;
        dfs(v,u,t);dp[u]+=dp[v]+1;
    }
    dp[u]=max(dp[u]-t,0);
    return dp[1];
}
int main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();add(x,y);add(y,x);
    }
    int l=0,r=1<<30,ans;
    while (l<=r){
        memset(dp,0,sizeof(dp));
        int mid=l+r>>1;
        if (!dfs(1,0,mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}