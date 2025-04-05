#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,pre,nxt;
}edge[1000100];
int head[1000100],n,m,q,tot,b[1000100],p[1000100],ans[1000100],cnt,fa[1000100];
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int read(){
    int res=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return res;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].pre=u;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
int main(){file();
    n=read();m=read();
    for (int i=0;i<=n;i++)fa[i]=i;
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    int q=read();
    for (int i=1;i<=q;i++){
        b[i]=read();p[b[i]]=1;
    }tot=n-q;
    for (int i=1;i<=2*m;i++){
        int x=edge[i].pre,y=edge[i].ver;
        if (p[x]||p[y])continue;
        int fx=find(x),fy=find(y);
        if (fx!=fy)tot--,fa[fx]=fy;
    }
    ans[q+1]=tot;
    for (int i=q;i>=1;i--){
        int u=b[i];tot++;p[u]=0;
        for (int j=head[u];j;j=edge[j].nxt){
            int v=edge[j].ver;if (p[v])continue;
            int fu=find(u),fv=find(v);
            if (fu!=fv)tot--,fa[fu]=fv;
        }
        ans[i]=tot;
    }
    for (int i=1;i<=q+1;i++){
        printf("%d\n",ans[i]);
    }
}
