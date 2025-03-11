> 给一个$n$个点$m$条边的无向图$G$，求一个长度不超过$4n$的路径序列，使得对于给定一个$01$序列满足$a[i]=1$的点$i$经过奇数次，$a[i]=0$的点$i$经过偶数次

我们可以对于给定序列在图上dfs，经历一次就异或$1$，目标让序列变为全是$0$

路径序列长度不超过$4n$也就是经历的边数不超过$4n-1$

考虑对于每个点都要经历最少的次数来保证长度，很容易想到树形结构，对于每个节点，先异或$1$，然后进入所有儿子，而这个点有多少儿子就异或几次(从每个儿子回来再进入新的儿子，最后一个儿子回来再回到这个点的父亲)

但如果这个点异或到最后成了$1$的话，我们可以把让它回到父亲节点再下来再回去，这样父亲节点和这个节点就再异或$1$

最后根节点如果异或成$1$的话，我们就对答案序列$-3$，也就是我们不让根节点的最后一个儿子回到根节点了，因为根节点没有父节点，这样就少了一次异或$1$

可以得证，每条边最多经历$4$次，根节点到最后一个儿子的连边最多$2$次

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=200010;
struct EDGE{
    int ver,nxt;
}edge[N];
int n,m,head[N],cnt,vis[N],a[N],ans[N<<2],s;
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
void dfs(int u,int fa){
    vis[u]=1;ans[++cnt]=u;a[u]^=1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa||vis[v])continue;
        dfs(v,u);ans[++cnt]=u;a[u]^=1;
    }if (a[u]){
        a[u]^=1;a[fa]^=1;ans[++cnt]=fa;ans[++cnt]=u;
    }
}
int main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();add(x,y);add(y,x);
    }
    for (int i=1;i<=n;i++){
        a[i]=read();if (a[i])s=i;
    }cnt=0;
    if (s)dfs(s,-1);
    for (int i=1;i<=n;i++){
        if (!vis[i]&&a[i]){
            printf("-1");return 0;
        }
    }
    if (cnt>1&&ans[cnt-1]==-1)cnt-=3;
    printf("%d\n",cnt);
    for (int i=1;i<=cnt;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
```