#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1000010;
struct EDGE{
    int ver,nxt,dis;
}edge[N<<1];
int n,m,cnt,head[N<<1],txor[N],trie[N][2],bo[N],ans;
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
void add(int u,int v,int t){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    edge[cnt].dis=t;
    head[u]=cnt;
}
void dfs(int u,int now,int fa){
    txor[u]=now;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa)continue;
        dfs(v,now^edge[i].dis,u);
    }
}
int insert(int x){
    int u=0;
    for (int i=30;i>=0;i--){
        int v=(txor[x]>>i)&1;
        if (!trie[u][v])trie[u][v]=++cnt;
        u=trie[u][v];
    }
}
int query(int x)
{
    int u=0,ans=0;
    for (int i=30;i>=0;i--)
    {
        int v=(txor[x]>>i)&1;
        if (trie[u][!v])u=trie[u][!v],ans+=1<<i;
        else u=trie[u][v];
    }
    return ans;
}
int main(){
    n=read();
    for (int i=1;i<=n-1;i++){
        int x=read(),y=read(),t=read();
        add(x,y,t);add(y,x,t);
    }
    cnt=0;dfs(1,0,0);
    for (int i=1;i<=n;i++)insert(i);
    for (int i=1;i<=n;i++)ans=max(ans,query(i));
    printf("%d",ans);
    return 0;
}