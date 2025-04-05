<!--more-->

[比赛链接](https://www.luogu.com.cn/contest/22686)

## A 亵渎

按生物血量升序排序，然后对于相邻的两个怪的血量差$c$，有两种可能：

> $c=0$或$1$，这样的会因为前面一个怪死掉而死掉

> $c>1$，这样会在前面一个怪死掉以后，还需使用$c-1$个亵渎这个怪才能死

复杂度$O(n\log n)$

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[100001],n,ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ans+=a[1]; 
    for (int i=2;i<=n;i++)
    {
        if (a[i]>(a[i-1]+1))ans+=a[i]-a[i-1]-1;
    }
    cout<<ans;
}
```

## B 雁

我们发现如果要“一字型”的话，就是保证所有相邻两个数差为$0$

而我们对原序列差分出来，然后看差分后的序列，对于每个区间操作，就是两个单点操作（前后异号且变化量都为$1$）或一个单点操作（$\pm 1$）了

“人字型”的话，我们从$1$到$n$枚举最大值的位置$i$

- 对于$a[1..i-1]$中的任意位置$j$，$a[j]$满足$a[j]<a[j+1]$，也就是$a[j]-a[j+1]\leq 1$

- 对于$a[i+1..n]$的任意位置$j$，$a[j]$满足$a[j]>a[j+1]$，也就是$a[j]-a[j+1]\geq 1$

我们可以差分出来，进行区间$\pm1$的操作就是对差分出的序列进行下面两种操作

- $a[i]+1,a[j]-1,i\not =j$

- $a[i]\pm 1$

记$dif[i]=a[i]-a[i+1]$

于是我们枚举最大值的时候，最大值的位置为$i$时的答案为：

$$max(l,r)$$

$$l=\sum_{j=1}^{i-1}[dif[j]>0]\times  (1+dif[j])$$

$$r=\sum_{j=i}^{n-1}[dif[j]<0]\times  (1-dif[j])$$

对于人字型的这种做法的正确性证明，可以参考一字型自行证明

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1000010,inf=2e9+7;
int n,m,a[N],pos,neg;
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
int main(){
    n=read();
    for (int i=1;i<=n;i++)a[i]=read();
    for (int i=1;i<n;i++)a[i]-=a[i+1];
    for (int i=1;i<n;i++)if (a[i]>0)pos+=a[i];else neg-=a[i];
    int ans=inf;
    int l=a[1]>=0?1+a[1]:0,r=0;
    for (int i=2;i<n;i++){
        r+=a[i]<=0?1-a[i]:0;
    }
    for (int i=2;i<n;i++){
        ans=min(ans,max(l,r));
        l+=a[i]>=0?1+a[i]:0;
        r-=a[i]<=0?1-a[i]:0;
    }
    printf("%d",min(max(neg,pos),ans));
    return 0;
}
```

## C 树

我们可以预处理出所有节点x子树内的最长链$under[x]$，子树外的最长链$above[x]$，除去所有子树内最长链上的边以外子树内的第二长链$under2[x]$

具体过程见代码的$dp1$和$dp2$

对于每个询问$x,y$有两种情况：

- 对于$lca(x,y)\not=x$且$lca(x,y)\not=y$的时候，答案就是$(x,y)+under[x]+under[y]$

- 对于$lca(x,y)=x$的时候，我们判断一下$y$是否在$x$子树内的最长链上，如果是的话答案为$(x,y)+under[y]+max(above[x],under2[x])$，否则答案为$(x,y)+under[y]+max(above[x],under[x])$

记录$x$在最长链上的儿子是哪个，让$y$跳到$x$的儿子上，就可以判断$y$是否在$x$的子树内最长链上了

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1000010;
struct EDGE{
    int ver,pre,num,dis,nxt;
}edge[N];
int n,m,head[N],cnt,dfs_cnt,p;
int siz[N],depth[N],fa[N],dfn[N],son[N],top[N];
int under[N],under_2[N],under_son[N],above[N],dis[N];
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
void dfs1(int u,int last){
    siz[u]=1;depth[u]=depth[last]+1;fa[u]=last;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==last)continue;
        dis[v]=dis[u]+edge[i].dis;
        dfs1(v,u);siz[u]+=siz[v];
        if (siz[v]>siz[son[u]])son[u]=v;
    }
}
void dfs2(int u,int front){
    dfn[u]=++dfs_cnt;top[u]=front;
    if (son[u])dfs2(son[u],front);
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (v!=fa[u]&&v!=son[u])dfs2(v,v);
    }
}
void dp1(int u){
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa[u])continue;dp1(v);
        if (under[v]+edge[i].dis>under[u]){
            under_2[u]=under[u];under[u]=under[v]+edge[i].dis;
            under_son[u]=v;
        }else{
            if (under[v]+edge[i].dis>under_2[u]){
                under_2[u]=under[v]+edge[i].dis;
            }
        }
    }
}
void dp2(int u){
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;if (v==fa[u])continue;
        if (v==under_son[u]){
            above[v]=max(under_2[u],above[u])+edge[i].dis;
        }else{
            above[v]=max(under[u],above[u])+edge[i].dis;
        }dp2(v);
    }
}
void add(int u,int v,int t){
    edge[++cnt].ver=v;
    edge[cnt].dis=t;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
bool query(int x,int y,int z){
    return under_son[x]==(x!=y?son[x]:z);
}
int ask(int tx,int ty){
    if (tx==ty){
        return under[tx]+max(under_2[tx],above[tx]);
    }
    int x=tx,y=ty,lca=0,last=0;
    while (top[x]!=top[y]){
        if (depth[top[x]]>depth[top[y]])last=top[x],x=fa[top[x]];
        else last=top[y],y=fa[top[y]];
    }
    if (depth[x]<depth[y])lca=x;else lca=y;int res=dis[tx]+dis[ty]-2*dis[lca];
    if (lca==tx){
        return res+under[ty]+max(above[tx],query(tx,y,last)?under_2[tx]:under[tx]);
    }
    if (lca==ty){
        return res+under[tx]+max(above[ty],query(ty,x,last)?under_2[ty]:under[ty]);
    }
    return res+under[tx]+under[ty];
}
int main(){
    n=read();m=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read(),t=read();
        add(x,y,t);add(y,x,t);
    }
    dfs1(1,0);dfs2(1,1);dp1(1);dp2(1);
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        printf("%d\n",ask(x,y));
    }
    return 0;
}

```

## D 无畏天马

存图挺难的，按dfs序跑，一个全局变量$v$记录出边指向的点，然后对于一个箱子解锁的时间，就相当于我们再走一条走廊，开箱子不需要时间

中间的点的$dis$都设为$0$(迎合读入)，有箱子的点$dis$设为古画的数量

之后就是裸的树形$dp$分组背包了，记$(u,v)$表示$u$到$v$这条边的边权，那么$dp$式就是

$$f[u][j]=max(f[v][k]+f[v][j-(u,v)-k]),f[u][0]=dis[u]$$

细节方面，我们既然要出去，那一定每一条路径都要经历“往里走”和“往外走”两个过程，也就是一定会走两次，存图的时候边权自动双倍就好了

还有个问题，就是如果你恰好用了$s$秒，你出门是会和水猿碰面的，所以时间在读入的时候就要$-1$

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define reg register
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,dfs_cnt,size[orz],v=2;
int dis[orz],s,l,r,f[5001][1001],ans,tim[orz];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
inline void add(int u,int v,int t){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    edge[cnt].dis=t;
    head[u]=cnt;
}
inline void dfs(int u){
    int t=read()<<1,tmp=read();v++;add(u,v,t);
    if (tmp){
        add(v,v+1,tim[++dfs_cnt]);dis[++v]=tmp;
    }else{
        dfs(v);
    }
    t=read()<<1;tmp=read();v++;add(u,v,t);
    if (tmp){
        add(v,v+1,tim[++dfs_cnt]);dis[++v]=tmp;
    }else{
        dfs(v);
    }
}
inline void dp(int u){
    f[u][0]=dis[u];
    for (reg int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;dp(v);
        for (reg int j=s;j>=edge[i].dis;--j){
            for (reg int k=j-edge[i].dis;k>=0;--k){
                f[u][j]=max(f[u][j],f[v][k]+f[u][j-k-edge[i].dis]);
            }
        }
    }
}
int main(){
    n=read();s=read()-1;
    for (reg int i=1;i<=n;i++){
        tim[i]=read();
    }
    int t=read()<<1,tmp=read();add(1,2,t);
    if (!tmp)dfs(2);
    else add(2,3,tim[1]),dis[3]=tmp;
    dp(1);
    for (reg int i=1;i<=s;i++){
        ans=max(ans,f[1][i]);
    }
    printf("%d",f[1][s]);
    return 0;
}
```

## E 寻

本来zrzring想把这个题出成签到题的，后来被qwaszx加强了，于是就有了这道题

- [solution by qwaszx](https://www.luogu.com.cn/blog/qwaszx/ti-xie-soi-round-1-c-xun)

#### 算法一

考虑dp，$f_{i,j,k}$表示从$(0,0)$走到$(i,j)$，用了$k$个斜步的方案数，那么有

$$
\begin{array}{ccc}f_{i,0,0}=f_{0,i,0}=1\\
f_{i,j,0}=f_{i-1,j,0}+f_{i,j-1,0}(i,j>0)\\
f_{i,j,k}=f_{i-1,j,k}+f_{i,j-1,k}+f_{i-1,j-1,k-1}(i,j,k>0)
\end{array}
$$

复杂度$O(n^2m)$，期望得分$20$分

#### 算法二

考虑没有斜步怎么做，这时的方案数即$\binom{2n}{n}$，因为向上和向右一共要走$2n$步， 其中向上向右各$n$步.从这$2n$步里选出$n$步向上即可.

现在考虑斜步，假设有$k$个斜步，那么向上的步和向右的步都还剩$n-k$个，再加上斜步一共有$2n-k$步，从$2n-k$步里选出$k$个斜步，再从剩下$2n-2k$步里选出$n-k$个向上的步，方案数为

$$
\binom{2n-k}{k}\binom{2(n-k)}{n-k}
$$

枚举走了几个斜步，从$(0,0)$走到$(n,n)$的方案数即

$$
\sum_{k=0}^{m}\binom{2n-k}{k}\binom{2(n-k)}{n-k}
$$

计算单个$n$的复杂度是$O(m)$，总复杂度$O(nm)$，期望得分$50$分.

#### 算法三

考虑化一下算法二中的式子.

$$
\begin{aligned}&\sum_{k=0}^m\binom{2n-k}{k}\binom{2(n-k)}{n-k}\\
=&\sum_{k=n-m}^n\binom{n+k}{n-k}\binom{2k}{k}\\
=&\sum_{k=n-m}^n\binom{n+k}{2k}\binom{2k}{k}\\
=&\sum_{k=n-m}^n\binom{n+k}{k}\binom{n}{k}\\
=&\sum_{k=n-m}^n\binom{n}{k}\sum_{j}\binom{n}{j}\binom{k}{k-j}\\
=&\sum_{j}\binom{n}{j}\sum_{k=n-m}^n\binom{n}{k}\binom{k}{j}\\
=&\sum_j\binom{n}{j}\binom{n}{j}\sum_{k=n-m}^n\binom{n-j}{k-j}\\
=&\sum_{j}\binom{n}{j}^2\sum_{k=n-m-j}^{n-j}\binom{n-j}{k}\end{aligned}
$$

发现后面的

$$
\sum_{k=n-m-j}^{n-j}\binom{n-j}{k}
$$

是一个只和$n-j$与$m$有关的东西.如果我们处理出这个东西就可以使用$NTT$优化到$O(n\log n)$.

考虑

$$
S(n)=\sum_{k=n-m}^n\binom{n}{k}
$$

从$n$转移到$n+1$:

$$
\begin{aligned}
S(n+1)
&=\sum_{k=n-m+1}^{n+1}\binom{n+1}{k}\\
&=\sum_{k=n-m+1}^{n+1}\binom{n}{k}+\binom{n}{k-1}\\
&=2\sum_{k=n-m}^n\binom{n}{k}+\binom{n}{n+1}-\binom{n}{n-m}\\
&=2S(n)-\binom{n}{n-m}\end{aligned}
$$

于是可以递推处理出来$S$.

复杂度$O(n\log n)$，期望得分$100$分.

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int mod=998244353,N=2e6,g=3,gi=332748118;
long long fac[N],ifac[N],inv[N];
int n,a[N],b[N],rev[N],m;
int qpower(int a,int b)
{
    int ans=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)ans=1ll*ans*a%mod;
    return ans;
}
void NTT(int a[],int n,int f)
{
    for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int i=1;i<n;i<<=1)
    {
        int wn=qpower(f==1?g:gi,(mod-1)/(i<<1));
        for(int j=0,r=i<<1;j<n;j+=r)
        {
            int w=1;
            for(int k=0;k<i;k++,w=1ll*w*wn%mod)
            {
                int x=a[j+k],y=1ll*w*a[i+j+k]%mod;
                a[j+k]=(x+y)%mod,a[i+j+k]=(x-y)%mod;
            }
        }
    }
    if(f==-1)
    {
        int iv=qpower(n,mod-2);
        for(int i=0;i<n;i++)a[i]=1ll*a[i]*iv%mod;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    fac[0]=ifac[0]=inv[1]=fac[1]=ifac[1]=1;
    for(int i=2;i<=2*n;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=ifac[i-1]*inv[i]%mod;
    }
    int pw=1;
    for(int i=0;i<=n;i++)a[i]=1ll*ifac[i]*ifac[i]%mod,b[i]=1ll*a[i]*pw%mod,pw=(2ll*pw-(i>=m?1ll*fac[i]*ifac[m]%mod*ifac[i-m]:0))%mod;
    int l=1;while(l<=(n<<1))l<<=1;
    for(int i=1;i<l;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?(l>>1):0);
    NTT(a,l,1),NTT(b,l,1);
    for(int i=0;i<l;i++)a[i]=1ll*a[i]*b[i]%mod;
    NTT(a,l,-1);
    pw=1;int ans=0;
    for(int i=0;i<=n;i++)ans=(ans+1ll*pw*a[i]%mod*fac[i]%mod*fac[i])%mod,pw=(1ll*pw*pw+2)%mod;
    cout<<(ans%mod+mod)%mod<<endl;
}

```

## F 觅

- [solution by qwaszx](https://www.luogu.com.cn/blog/qwaszx/ti-xie-soi-round-1-d-mi)

#### 算法一

考虑dp，$f_{i,j}$表示从$(0,0)$走到$(i,j)$的方案数，那么有
$$
f_{i,j}=
\begin{cases}
1&ij=0\\
f_{i-1,j}+f_{i,j-1}+f_{i-1,j-1}&ij\neq 0
\end{cases}
$$
复杂度$O(n^2)$，期望得分$30$分

#### 算法二

考虑没有斜步怎么做，这时的方案数即$\binom{2n}{n}$，因为向上和向右一共要走$2n$步， 其中向上向右各$n$步.从这$2n$步里选出$n$步向上即可.

现在考虑斜步，假设有$k$个斜步，那么向上的步和向右的步都还剩$n-k$个，再加上斜步一共有$2n-k$步，从$2n-k$步里选出$k$个斜步，再从剩下$2n-2k$步里选出$n-k$个向上的步，方案数为

$$
\binom{2n-k}{k}\binom{2(n-k)}{n-k}
$$

枚举走了几个斜步，从$(0,0)$走到$(n,n)$的方案数即

$$
\sum_{k=0}^n\binom{2n-k}{k}\binom{2(n-k)}{n-k}
$$

计算单个$n$的复杂度是$O(n)$，总复杂度$O(n^2)$，期望得分$30$分.

#### 算法三

考虑化一下算法二中的式子.

$$
\begin{aligned}
&\sum_{k=0}^n\binom{2n-k}{k}\binom{2(n-k)}{n-k}\\
=&\sum_{k=0}^n\binom{n+k}{n-k}\binom{2k}{k}\\
=&\sum_{k=0}^n\binom{n+k}{2k}\binom{2k}{k}\\
=&\sum_{k=0}^n\binom{n+k}{k}\binom{n}{k}\\
=&\sum_{k=0}^n\binom{n}{k}\sum_{j}\binom{n}{j}\binom{k}{k-j}\\
=&\sum_{j}\binom{n}{j}\sum_{k=0}^n\binom{n}{k}\binom{k}{j}\\
=&\sum_j\binom{n}{j}\binom{n}{j}\sum_{k=0}^n\binom{n-j}{k-j}\\
=&\sum_{j}\binom{n}{j}^22^{n-j}
\end{aligned}
$$

可以使用$NTT$优化，复杂度$O(n\log n)$，期望得分$60$分

#### 算法四

考虑数列$f_n$表示从$(0,0)$走到$(n,n)$的方案数，$g_n$表示从$(0,0)$走到$(n,n)$且不越过(可以碰到)对角线的方案数，考虑第一步有三种走法:

1. 走一个斜步，此时还需要从$(1,1)$走到$(n,n)$，方案数是$f_{n-1}$

2. 向右走一步，然后枚举第一次碰到对角线的位置$(k,k)$，因为是第一次碰到，所以碰到对角线的这一步一定是向上走的，所以相当于从$(1,0)$走到$(k,k-1)$并且中间任何一个位置$(i,j)$都满足$i>j$，向下平移一格就是从$(0,0)$走到$(k-1,k-1)$且不越过对角线，方案数是$g_{k-1}$;还需要从$(k,k)$走到$(n,n)$，方案数是$f_{n-k}$，总的方案数就是

$$
\sum_{k=1}^n g_{k-1}f_{n-k}=\sum_{k=0}^{n-1}g_{n-1-k}f_k
$$

3. 向上走一步，是向右走的对称情况，方案数同上

所以有

$$
f_n=f_{n-1}+2\sum_{k=0}^ng_{n-1-k}f_{k}
$$

以及显然的

$$
f_0=1
$$

设$f$的生成函数是$F(x)$，$g$的生成函数是$G(x)$，那么有

$$
\begin{aligned}
F(x)
&=\sum_{i\geq 0}f_ix^i\\
&=f_0+\sum_{i\geq 1}x^i\left(f_{i-1}+2\sum_{k=0}^{i-1}f_kg_{i-1-k}\right)\\
&=1+xF(x)+2xF(x)G(x)
\end{aligned}
$$

解方程就得到

$$
F(x)=\frac{1}{1-x-2xG(x)}
$$

现在来考虑$g$，根据和之前差不多的分析方法可以得到

$$
g_n=g_{n-1}+\sum_{k=0}^{n-1}g_kg_{n-1-k},g_0=1
$$

所以对$G(x)$就有

$$
\begin{aligned}
G(x)
&=\sum_{i\geq 0}g_ix^i\\
&=g_0+\sum_{i\geq 1}x^i\left(g_{i-1}+\sum_{k=0}^{i-1}g_kg_{i-1-k}\right)\\
&=1+xG(x)+xG(x)^2
\end{aligned}
$$

解方程就得到

$$
G(x)=\frac{1-x\pm\sqrt{x^2-6x+1}}{2x}
$$

其中有一个根需要舍去，带入$x=0$检验:

$$
\lim_{x\to 0}\frac{1-x\pm\sqrt{x^2-6x+1}}{2x}=\lim_{x\to 0}\frac{2}{1-x\mp\sqrt{x^2-6x+1}}=\frac{2}{1\mp 1}
$$

发现根号前面取加号会使得这个极限是$+\infty$而取减号是$1$，因为$g_0=1$所以我们需要取减号.于是

$$
G(x)=\frac{1-x-\sqrt{x^2-6x+1}}{2x}
$$

带入到$F(x)$的式子里就得到

$$
F(x)=\frac{1}{\sqrt{x^2-6x+1}}
$$

把这个东西用多项式技术展开一下就能得到$f$，复杂度$O(n\log n)$，期望得分$80$分

#### 算法五

利用$f$的生成函数可以得到一些有用的东西.在等式两边求导得到

$$
F'(x)=-\frac{2x-6}{2(x^2-6x+1)\sqrt{x^2-6x+1}}=\frac{3-x}{x^2-6x+1}F(x)
$$

也就是

$$
(x^2-6x+1)F'(x)-(3-x)F(x)=0
$$

展开$F(x)$以及$F'(x)$就得到

$$
\sum_{i\geq 0}(x^2-6x+1)if_ix^{i-1}-\sum_{i\geq 0}(3-x)f_ix^i=0
$$

整理一下得到

$$
\sum_{i\geq 0}(i+1)f_ix^{i+1}-\sum_{i\geq 0}(6i+3)f_ix^i+\sum_{i\geq 0}if_ix^{i-1}=0
$$

因为等式右边是$0$，所以对任意$i\geq 0$有$x^{i+1}$项的系数为$0$，所以有

$$
(i+1)f_{i}-3(2i+3)f_{i+1}+(i+2)f_{i+2}=0
$$

即

$$
(i+2)f_{i+2}=3(2i+3)f_{i+1}-(i+1)f_i
$$

按照这个式子递推，复杂度$O(n)$，期望得分$100$分+神秘奖励


```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
const int N=2e6;
int n,inv[N],f[N];
int main()
{
    scanf("%d",&n);
    inv[1]=1;for(int i=2;i<=n;i++)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
    f[0]=1,f[1]=3;
    for(int i=0;i<=n-2;i++)
        f[i+2]=(3ll*(2*i+3)*f[i+1]-1ll*(i+1)*f[i])%mod*inv[i+2]%mod;
    int ans=0,g=1;
    for(int i=0;i<=n;i++)ans=(ans+1ll*g*f[i])%mod,g=(1ll*g*g+2)%mod;
    cout<<(ans%mod+mod)%mod<<endl;
}
```


#### ~~算法六~~

~~使用算法一进行打表，将打出来的表丢到OEIS上，找到这个数列的递推公式进行计算，复杂度O(n)，期望得分100分但没有神秘奖励~~