#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[1000100];
int head[1000100],n,m,cnt;
int f[1000100][2],p[1000100];
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
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int u,int last){
    f[u][0]=0;f[u][1]=1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (v==last)continue;dfs(v,u);
        f[u][0]+=f[v][1];
        f[u][1]+=min(f[v][0],f[v][1]);
    }
}
int main(){file();
    n=read();
    for (int i=1;i<=n;i++){
        int u=read(),size=read();
        for (int j=1;j<=size;j++){
            int v=read();add(u,v);add(v,u);p[v]=1;
        }
    }
    int root=0;while(p[root])root++;dfs(root,-1);
    printf("%d",min(f[root][1],f[root][0]));
    return 0;
}