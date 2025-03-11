$GSS$系列第2题，看似和第3题一样都是第1题的升级版，然而为啥这个2就比其他俩变态这么多呢。。。

一个套路，看到去重就想到离线

于是我们把询问离线存下来，按$r$关键字排序，每次从$i=1$开始往线段树里扔$a[i]$

我们的线段树要维护什么呢，加进来一个数我们要改变什么呢

首先，我们建立一个新的数组$b[j]$，考虑对于加进来的$a[i]$，设$a[i]$这个值上一次出现的位置为$pre[i]$，因为我们要去重，所以我们加进来的数只会对区间$[pre[i]+1,i]$造成贡献，于是我们可以让$b[j]$记录去重后的区间$[j,i]$的和，然后我们对于询问$[l,i]$就直接访问$b$就好了

有两个问题，第一，万一之前某一历史时候计算的$[l,j](l\leq j<i)$比区间$[l,i]$更优呢，第二，直接访问$b$复杂度不对啊

所以我们可以把$b$建成一棵线段树维护以下$4$个信息

>对于$b$的区间最大值$max$

>对于历史$b$的区间最大值$ans$

>对于$b$更新$a[i]$时加法的$tag$

>对于历史$tag$的最大值

如果看不懂请仔细回想之前线段树区间加的tag的精髓(雾)

这样我们就可以跑一个线段树求解了，$pushdown$的写法建议大家先思考思考，这是个锻炼的好机会qwq

$lazy$的时候要先更新$max$再更新$ans$，$pushdown$的时候要先更新$ans$再更新$max$，这一点要注意

来看$pushdown$的片段，这里先更新$ans$的原因是$lazy\_max$涵盖了$lazy\_add$的信息，也就是我们如果先把$tmax$加上了$lazy\_add$，在部分情况下，等于把这个贡献计算了两遍

```cpp
tans[ls]=max(tans[ls],tmax[ls]+lazy_max[now]);
tans[rs]=max(tans[rs],tmax[rs]+lazy_max[now]);
tmax[ls]+=lazy_add[now];
tmax[rs]+=lazy_add[now];
```

而$lazy$的时候先更新$max$再更新$ans$这个理由我不用多说了吧



```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (now<<1)
#define rs (now<<1|1)
using namespace std;
const int N=100010,inf=1<<30;
struct node{
    int l,r,id;
}q[N];
int n,m,tmax[N<<2],tans[N<<2],pre[N],pos[N<<1],a[N],ans[N],lazy_add[N<<2],lazy_max[N<<2];
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
int cmp(node a,node b){
    return a.r<b.r;
}
void pushup(int now){//迷你pushup
    tmax[now]=max(tmax[ls],tmax[rs]);
    tans[now]=max(tans[ls],tans[rs]);
}
void pushdown(int now,int l,int r){//中等pushdown
    int mid=l+r>>1;
    tans[ls]=max(tans[ls],tmax[ls]+lazy_max[now]);
    tans[rs]=max(tans[rs],tmax[rs]+lazy_max[now]);
    tmax[ls]+=lazy_add[now];
    tmax[rs]+=lazy_add[now];
    lazy_max[ls]=max(lazy_max[ls],lazy_add[ls]+lazy_max[now]);
    lazy_max[rs]=max(lazy_max[rs],lazy_add[rs]+lazy_max[now]);
    lazy_add[ls]+=lazy_add[now];
    lazy_add[rs]+=lazy_add[now];
    lazy_add[now]=0;
    lazy_max[now]=0;
}
void lazy(int now,int t){//中等lazy
    tmax[now]+=t;
    tans[now]=max(tans[now],tmax[now]);
    lazy_add[now]+=t;
    lazy_max[now]=max(lazy_max[now],lazy_add[now]);
}
void add(int now,int l,int r,int x,int y,int t){
    if (x<=l&&r<=y){
        lazy(now,t);return;
    }int mid=l+r>>1;pushdown(now,l,r);
    if (mid>=x)add(ls,l,mid,x,y,t);
    if (mid+1<=y)add(rs,mid+1,r,x,y,t);
    pushup(now);
}
int query(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tans[now];
    }int mid=l+r>>1;pushdown(now,l,r);int res=-inf;
    if (mid>=x)res=max(res,query(ls,l,mid,x,y));
    if (mid+1<=y)res=max(res,query(rs,mid+1,r,x,y));
    return res;
}
int main(){//file();
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();pre[i]=pos[a[i]+(int)1e5];pos[a[i]+(int)1e5]=i;
    }m=read();
    for (int i=1;i<=m;i++){
        q[i].l=read();q[i].r=read();q[i].id=i;
    }sort(q+1,q+m+1,cmp);int j=1;
    for (int i=1;i<=n;i++){
        add(1,1,n,pre[i]+1,i,a[i]);//直接把b扔树上，就是b为叶子节点
        for (;j<=m&&q[j].r<=i;j++){
            ans[q[j].id]=query(1,1,n,q[j].l,q[j].r);
        }
    }
    for (int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
```

