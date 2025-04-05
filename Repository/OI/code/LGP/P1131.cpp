#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[500100];
int head[500100],n,m,cnt,ans;
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
void dfs(int u,int last){
    int tot=0,maxx=0,res=0;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (v==last){continue;}dfs(v,u);
        if (edge[i].dis>maxx){
            res+=tot*(edge[i].dis-maxx);maxx=edge[i].dis;
        }else{
            res+=maxx-edge[i].dis;
        }
        tot++;
    }ans+=res;
    for (int i=head[last];i;i=edge[i].nxt){
        if (edge[i].ver==u)edge[i].dis+=maxx;
    }
}
signed main(){file();
    n=read();int root=read();
    for (int i=1;i<=n-1;i++){
        int u=read(),v=read(),t=read();
        add(u,v,t);add(v,u,t);
    }
    dfs(root,0);
    printf("%lld",ans);
    return 0;
}
