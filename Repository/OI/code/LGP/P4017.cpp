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
const int N=500010,p=80112002;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
struct EDGE{
    int ver,nxt;
}edge[N];
int n,m,d[N],dp[N],head[N],cnt;
long long ans;
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
queue<int>q;
int main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();add(x,y);d[y]++;
    }
    for (int i=1;i<=n;i++){
        if (!d[i])q.push(i),dp[i]=1;
    }
    while (!q.empty()){
        int u=q.front();q.pop();if (!head[u])ans=(ans+dp[u])%p;
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;d[v]--;dp[v]=(dp[u]+dp[v])%p;
            if (!d[v])q.push(v);
        }
    }
    printf("%lld\n",ans);
    return 0;
}