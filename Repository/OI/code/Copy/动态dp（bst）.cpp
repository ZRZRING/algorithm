// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#define nroot(x) (a[a[x].fa].ch[1]==x||a[a[x].fa].ch[0]==x)
#define getwh(x) (a[a[x].fa].ch[1]==x)
using namespace std;
const int N=5e5,INF=1e9;
struct Matrix
{
    int a[2][2];
    Matrix operator *(const Matrix &b)const
    {
        Matrix t;
        t.a[0][0]=max(a[0][0]+b.a[0][0],a[0][1]+b.a[1][0]);
        t.a[0][1]=max(a[0][0]+b.a[0][1],a[0][1]+b.a[1][1]);
        t.a[1][0]=max(a[1][0]+b.a[0][0],a[1][1]+b.a[1][0]);
        t.a[1][1]=max(a[1][0]+b.a[0][1],a[1][1]+b.a[1][1]);
        return t;
    }
};
struct Node
{
    int fa,ch[2],f[2];
    Matrix s;
}a[N];
int n,m,w[N],fst[N],to[N],nxt[N],mm;
void ade(int u,int v){to[++mm]=v,nxt[mm]=fst[u],fst[u]=mm;}
void pushup(int x)
{
    a[x].s=(Matrix){{{a[x].f[0],a[x].f[0]},{a[x].f[1],-INF}}};
    if(a[x].ch[0])a[x].s=a[a[x].ch[0]].s*a[x].s;
    if(a[x].ch[1])a[x].s=a[x].s*a[a[x].ch[1]].s;
}
void rotate(int x)
{
    int y=a[x].fa,z=a[y].fa,wh=a[y].ch[1]==x,w=a[x].ch[wh^1];
    if(nroot(y))a[z].ch[a[z].ch[1]==y]=x;a[x].fa=z;
    a[x].ch[wh^1]=y,a[y].fa=x;a[y].ch[wh]=w,a[w].fa=y;
    pushup(y),pushup(x);
}
void splay(int x)
{
    while(nroot(x))
    {
        int y=a[x].fa;
        if(nroot(y))rotate((getwh(x)==getwh(y)?y:x));
        rotate(x);
    }
}
void access(int x)
{
    for(int y=0;x;y=x,x=a[x].fa)
    {
        splay(x);
        if(a[x].ch[1])
        {
            int t=a[x].ch[1];
            a[x].f[0]+=max(a[t].s.a[0][0],a[t].s.a[1][0]);
            a[x].f[1]+=a[t].s.a[0][0];
        }
        if(y)
        {
            a[x].f[0]-=max(a[y].s.a[0][0],a[y].s.a[1][0]);
            a[x].f[1]-=a[y].s.a[0][0];
        }
        a[x].ch[1]=y,pushup(x);
    }
}
void dfs(int u,int fa)
{
    Node *z=a+u;z->f[1]=w[u];z->fa=fa;
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];if(v==fa)continue;
        dfs(v,u);z->f[0]+=max(a[v].f[0],a[v].f[1]),z->f[1]+=a[v].f[0];
    }
    z->s=(Matrix){{{z->f[0],z->f[0]},{z->f[1],-INF}}};
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",w+i);
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),ade(u,v),ade(v,u);
    dfs(1,0);
    for(int i=1,x,y;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(w[x]!=y)
        {
            access(x),splay(x);
            Node *z=a+x;z->f[1]+=y-w[x],pushup(x);w[x]=y;
        }
        splay(1);
        printf("%d\n",max(a[1].s.a[0][0],a[1].s.a[1][0]));
    }
}