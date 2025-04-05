#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
const int inf=1<<30;
int head[100010],cnt,cur[100010];
struct EDGE{
    int nxt,ver,dis;
}edge[100010];
queue <int> q;
int n,m,x,y,t,ans,dis[100010],S,T;
void add(int u,int v,int t){
    edge[cnt].ver=v;
    edge[cnt].dis=t;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
int bfs(){
    for (int i=1;i<=n;i++)dis[i]=0;
    dis[S]=1;q.push(S);
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].ver;
            if (dis[v]||edge[i].dis<=0)continue;
            dis[v]=dis[u]+1;q.push(v);
        }
    }
    return dis[T];
}
int dfs(int u,int now){
    if (u==T||!now)return now;
    int res=0,tmp;
    for (int i=cur[u];i!=-1&&now>0;i=edge[i].nxt){
        int v=edge[i].ver;cur[u]=i;
        if(dis[v]==dis[u]+1&&edge[i].dis>0){
            tmp=dfs(v,min(now,edge[i].dis));
            edge[i].dis-=tmp;edge[i^1].dis+=tmp;
            res+=tmp;now-=tmp;
        }
    }
    return res;
}
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
signed main(){file();
    memset(head,-1,sizeof(head));
    n=read(),m=read(),S=read(),T=read();
    for(int i=1;i<=m;i++){
        x=read(),y=read(),t=read();
        add(x,y,t);add(y,x,0);
    }
    while(bfs()){
        for(int i=1;i<=n;i++)cur[i]=head[i];
    	ans+=dfs(S,inf);
	}
    printf("%lld",ans);
 } 