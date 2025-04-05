#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE1{
    int dis,u,v;
}edge1[1000100];
struct EDGE{
    int dis,ver,nxt;
}edge[1000100];
int fa[1000100],cnt,head[1000100],n,m,x,y,q,start,end;
int my_log2[1000100],dep[1000100],f[100010][30],w[100010][30],vis[1000100];
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
inline int read(){
    int res=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
    return res;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void add(int u,int v,int t){
    edge[++cnt].dis=t;
    edge[cnt].nxt=head[u];
    edge[cnt].ver=v;
    head[u]=cnt;
}
int cmp(EDGE1 a,EDGE1 b){
    return a.dis>b.dis;
}
void kruscal(){
    sort(edge1+1,edge1+m+1,cmp);
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=m;i++){
        int x=edge1[i].u,y=edge1[i].v,fx=find(x),fy=find(y);
        if (fx!=fy){
            fa[fx]=fy;add(fx,fy,edge1[i].dis);add(fy,fx,edge1[i].dis);
        }
    }
}
void dfs(int now){
    vis[now]=1;
    for (int i=head[now];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (vis[v])continue;
        dep[v]=dep[now]+1;
        f[v][0]=now;w[v][0]=edge[i].dis;
        dfs(v);
    }
}
int lca(int x,int y){
    int ans=1<<30;
    if (dep[x]<dep[y])swap(x,y);
    for (int i=20;i>=0;i--){
        if (dep[f[x][i]]>=dep[y]){
            ans=min(ans,w[x][i]);x=f[x][i];
        }
    }
    if (x==y)return ans;
    for (int i=20;i>=0;i--){
        if (f[x][i]!=f[y][i]){
            ans=min(ans,min(w[x][i],w[y][i]));
            x=f[x][i];y=f[y][i];
        }
    }
    return min(ans,min(w[x][0],w[y][0]));
} 
int main(){//file();
    n=read();m=read();
    for (int i=1;i<=m;i++){
        edge1[i].u=read();edge1[i].v=read();edge1[i].dis=read();
    }
    kruscal();
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dep[i]=1;dfs(i);
            f[i][0]=i;w[i][0]=1<<30;
        }
    }
    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
            w[j][i]=min(w[j][i-1],w[f[j][i-1]][i-1]);
        }
    }
    q=read();
    for (int i=1;i<=q;i++){
        int x=read(),y=read();
        if (find(x)!=find(y))printf("-1\n");
        else printf("%d\n",lca(x,y));
    }
}