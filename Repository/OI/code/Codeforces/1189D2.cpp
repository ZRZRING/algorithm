#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010,inf=1e9+7;
struct EDGE{
    int pre,ver,dis,num,nxt;
}edge[N],ans[N];
int n,m,cnt=-1,tot,head[N],d[N],pre[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void add(int u,int v,int t){
    edge[++cnt].nxt=head[u];
    edge[cnt].pre=u;
    edge[cnt].ver=v;
    edge[cnt].dis=t;
    edge[cnt].num=cnt;
    head[u]=cnt;
}
int find(){
    int min_dis=inf,e=-1;
    for (int i=0;i<=cnt;i++){
        int u=edge[i].pre,v=edge[i].ver;
        if (!edge[i].dis||d[u]!=1&&d[v]!=1)continue;
        if (edge[i].dis<min_dis){
            min_dis=edge[i].dis; e=edge[i].num;
        }
    }
    int u=edge[e].pre,v=edge[e].ver;
    if (d[v]==1)e^=1;return e;
}
void debug(){
    for (int i=0;i<=cnt;i++){
        printf("%d %d %d\n",edge[i].pre,edge[i].dis,edge[i].ver);
    }printf("\n");
}
int main(){
    n=read();memset(head,-1,sizeof(head));
    for (int i=1;i<=n-1;i++){
        int x=read(),y=read(),t=read();
        add(x,y,t); add(y,x,t); d[x]++; d[y]++;
    }
    int u;
    while (1){
        int e=find();if (!~e)break;
        debug();
        u=edge[e].ver; pre[u]=edge[e].num; pre[edge[e].pre]=0;
        int tmp=edge[e].dis; ans[++tot].pre=edge[e].pre;
        while (d[u]!=1){
            int max_dis=0,nxt=0;
            for (int i=head[u];~i;i=edge[i].nxt){
                int dis=edge[i].dis,v=edge[i].ver;
                if (edge[i].dis>max_dis){
                    max_dis=dis; nxt=edge[i].num;
                }
            }
            int v=edge[nxt].ver; pre[v]=nxt; u=v;
        }
        ans[tot].dis=tmp;ans[tot].ver=u;
        while (pre[u]){printf("%d\n",u);
            edge[pre[u]].dis-=tmp;
            edge[pre[u]^1].dis-=tmp;
            u=edge[pre[u]].pre;
        }printf("\n");
    }
    for (int i=0;i<=cnt;i++){
        if (edge[i].dis){
            printf("NO\n"); return 0;
        }
    }
    printf("YES\n");
    for (int i=1;i<=n;i++){
        printf("%d %d %d\n",ans[tot].pre,ans[tot].ver,ans[tot].dis);
    }
    return 0;
}