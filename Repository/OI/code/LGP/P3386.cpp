#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int inf=1<<30;
int head[1000100],cnt;
struct EDGE{
    int nxt,ver,dis;
}edge[1000100];
queue <int> q;
int n1,n2,m,x,y,t,ans,dis[1000100],S,T;
void add(int u,int v,int t){
    edge[cnt].ver=v;
    edge[cnt].dis=t;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
int bfs(){
    for (int i=1;i<=T;i++)dis[i]=0;
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
    for (int i=head[u];i!=-1&&now>0;i=edge[i].nxt){
        int v=edge[i].ver;
        if(dis[v]==dis[u]+1&&edge[i].dis>0){
            tmp=dfs(v,min(now,edge[i].dis));
            edge[i].dis-=tmp;edge[i^1].dis+=tmp;
            res+=tmp;now-=tmp;
        }
    }
    return res;
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n1,&n2,&m);S=0;T=n1+n2+1;
    for (int i=1;i<=n1;i++){
        add(S,i,1);add(i,S,0);
    }
    for (int i=1;i<=n2;i++){
        add(i+n1,T,1);add(T,i+n1,0);
    }
    for (int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        if (x>n1||y>n2)continue;
        add(x,y+n1,1);add(y+n1,x,0);
    }
    while (bfs()){
    	ans+=dfs(S,inf);
	}
    printf("%lld",ans);
 } 
