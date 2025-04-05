## 思路

这个题有点吓人呢~~先在这里默认大家都会tarjan找割点了哈~~

如果你跑$tarjan$找割点然后把割点删掉跑$bfs$找连通块，这个$\mathcal{O}(n^2)$显然$T$飞了

所以我们要找一个边$tarjan$边计算的方法

首先如果一个点在一个连通块内，他的贡献仅仅是所有点和他的联系断了，所以割点的$ans$就是

$$2\times  (n-1)$$

难的是考虑割点，不过我们首先要知道：

>一个连通块的贡献$=$这个连通块的大小$\times  ($整个图大小$-$这个连通块大小$)$

这是一个通式，适用于以上所有的贡献求解，因为你的这个连通块和外面所有点都失去联系了，固然失去联系数就这么算了

对于一个割点$u$，它的子树(以$v$为根节点)中不能连接到割点的祖先的，这样的子树就被割成一个连通块，这些子树的贡献是

$$\sum_{dfn[u]\leq low[v]}size[v]\times  (n-size[v])$$

这样我们可以边$tarjan$边记录了，除去割点和被他割掉的子树就是一个连通块的，它们的贡献是

$$(n-sum-1)\times  (sum+1)$$

其中

$$sum=\sum_{dfn[u]\leq low[v]}size[v]$$

割点自己的贡献是$n-1$，合起来，割点的$ans$的计算公式为

$$ans=\sum_{dfn[u]\leq low[v]}size[v]\times  (n-size[v])+(n-sum-1)\times (sum+1)+(n-1)$$


```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int orz=1000100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt;
int ans[orz],dfn[orz],low[orz],dfs_cnt,size[orz];
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
void tarjan(int u){
    dfn[u]=low[u]=++dfs_cnt;size[u]=1;
    int sum=0,child=0;bool cut=false;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (!dfn[v]){
            tarjan(v);size[u]+=size[v];
            low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]){
                ans[u]+=size[v]*(n-size[v]);//累计分出去的儿子的贡献
                sum+=size[v];child++;
                if (u!=1||child>=2)cut=true;
            }
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (!cut)ans[u]=2*(n-1);
    else ans[u]+=(n-sum-1)*(sum+1)+(n-1);
    //外界是一个连通块，算上他们的贡献，然后自己是一个连通块，加上自己的贡献;
    //每个连通块的贡献都是该块size乘n-size
}
signed main(){
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    tarjan(1);
    for (int i=1;i<=n;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}
```
